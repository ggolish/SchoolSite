var _sock;
var _canvas, _ctx;
var _myship, _players = {};
var _bullets = [];
var _name = "", _color = "";

function setup() {
  // Get name and color from input elements:
  _name = document.getElementById("name").value;
  _color = document.getElementById("color").value;
  // Make "login" form go away:
  document.getElementById("login").style.display = "none";

  // Make canvas appear and setup drawing context:
  _canvas = document.getElementById("c");
  _canvas.style.display = "block";
  _ctx = _canvas.getContext("2d");
  _myship = new ship(400,300,_name, _color);

  _sock = new WebSocket("ws://cs.indstate.edu:60000/", "n/a");
  _sock.onopen = function(event) {
    _sock.send(JSON.stringify({command:"newplayer", name: _name, color: _color, x: 400, y: 300}));
    // Now safe to send data to the server.
    update();
  };

  _sock.onmessage = function(msg) {
    // received data in: msg.data
    var dat = JSON.parse(msg.data);
    switch(dat.command) {
      case "newplayer":
	if (_players[dat.name] == undefined)
	  _players[dat.name] = new ship(dat.x, dat.y, dat.name, dat.color);
	break;
      case 'update':
	if (_players[dat.name] == undefined)
	  _players[dat.name] = new ship(dat.x, dat.y, dat.name, dat.color);
	_players[dat.name].set(dat);
	break;
      case 'bullet':
	_bullets.push(new bullet(dat.x,dat.y,dat.angle));
	break;
    }
  };
}

function update(ev) {
  _ctx.clearRect(0,0,800,600);

  _myship.update();

  for(var p in _players)
    _players[p].draw();

  // Goes through all the bullets that have been fired:
  for(var b in _bullets) {
    _bullets[b].update();
    // If a bullet is used up, skip over it, it will removed by the next loop:
    if (_bullets[b].lifetime <= 0) continue;
    _bullets[b].draw();
  }
  // Get rid of all the old bullets:
  while(_bullets.length > 0 && _bullets[0].lifetime <= 0) _bullets.shift();

  setTimeout(update, 16);
}

function keydn(ev) {
  switch(ev.keyCode) {
    case 87: // w
    case 38: // up arrow
      _myship.thrusting = true;
      _myship.sendupdate();
      break;
    case 83: // s
    case 40: // down arrow
      _myship.teleport();
      _myship.sendupdate();
      break;
    case 32: // space
      _myship.firing = true;
      _myship.sendupdate();
      break;
    case 65: // a
    case 37: // left
      _myship.rotating = - Math.PI/24;
      _myship.sendupdate();
      break;
    case 68: // d
    case 39: // right
      _myship.rotating = Math.PI/24;
      _myship.sendupdate();
      break;
  }
}

function keyup(ev) {
  switch(ev.keyCode) {
    case 87: // w
    case 38: // up arrow
      _myship.thrusting = false;
      _myship.sendupdate();
      break;
    case 83: // s
    case 40: // down arrow
      break;
    case 32:
      _myship.firing = false;
      _myship.sendupdate();
      break;
    case 65: // a
    case 68: // d
    case 37: // left
    case 39: // right
      _myship.rotating = 0;
      _myship.sendupdate();
      break;
  }
}
