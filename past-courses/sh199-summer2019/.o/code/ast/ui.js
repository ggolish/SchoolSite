var _ctx = null, _sb = null;
var _width, _height;
var _time = 0;
var _score, _lives, _level;
var _ship;
var _goupdate = null;

function init() {
  var c = document.getElementById("c");
  _ctx = c.getContext("2d");
  c = document.getElementById("score");
  _sb = c.getContext("2d");
  resize();
  _ship = new Ship(_width/2,_height/2,0, _ctx);

  _score = 0;
  _lives = 3;
  _level = 0;
  resetplayfield();
  update_scoreboard();

  update();
}

function resetplayfield()
{
  _rocks = [];
  for(var i=0; i < Math.min(5+_level,10); i++)
    _rocks.push(new Rock());
  _ship.invulnerable = 60;
  _level++;
}

function update_scoreboard()
{
  _sb.clearRect(0,0,320,200);
  _sb.fillStyle = "black";
  _sb.font = "36pt Arial";
  var s = "00000".substr(0,5-_score.toString().length)+_score;
  _sb.fillText(s, 25, 50);
  for(var i=0; i < _lives; i++) {
    x = new Ship(40+(i*30),80, Math.PI/2, _sb);
    x.update();
  }
}

function resize() {
  c.width = _width = window.innerWidth-5;
  c.height = _height = window.innerHeight-5;
}

var _nr = [0, 0, 3, 2];
var _rs = [0, 100, 50, 25];

function update() {
  var i, sc = _score, li = _lives;
  _time++;
  _ctx.clearRect(0,0,_width,_height);

  _ship.update();
  for(i=0; i < _rocks.length; i++) {
    _rocks[i].update();
    if (_ship.hit(_rocks[i])) {
      _lives--;
      if (_lives === 0) return gameover();
      _ship.reset();
    }
  }
  for(i in _bullets) {
    var b = _bullets[i];
    b.update();
    if (b.lifetime < 0) {
      _bullets.splice(i, 1);
      continue;
    }
    var dontdraw = false;
    for(var j in _rocks) {
      if (_rocks[j].hit(b.x,b.y)) {
	var r = _rocks[j];
	_rocks.splice(j, 1);
	for(var k = 0; k < _nr[r.scale]; k++)
	  _rocks.push(new Rock(r));
	_bullets.splice(i, 1);
	_score += _rs[r.scale];
	dontdraw = true;
	break;
      }
    }
    if (!dontdraw) b.draw();
  }
  if (_rocks.length === 0) resetplayfield();
  for(i=0; i < _rocks.length; i++) {
    _rocks[i].draw();
  }
  if (sc != _score || li != _lives) update_scoreboard();
  setTimeout(update, 16);
}

function goupdate() {
  _ctx.clearRect(0,0,_width,_height);

  for(var i=0; i < _rocks.length; i++) {
    _rocks[i].update();
    _rocks[i].draw();
  }
  _goupdate = setTimeout(goupdate, 16);
}

function gameover()
{
  var go = document.getElementById("gameover");
  go.style.display = "block";
  go.style.top = (_height/2 - go.clientHeight/2) + "px";
  go.style.left = (_width/2 - go.clientWidth/2) + "px";
  goupdate();
}

function key(e) {
  switch(e.keyCode) {
    case 65:	// a (left)
      _ship.rotating = -5*Math.PI/180;
      break;
    case 68:	// d (right)
      _ship.rotating = 5*Math.PI/180;
      break;
    case 87:
      _ship.thrusting = true;
      break;
    case 32:
      _ship.firing = true;
      break;
    case 82: // R key
      if (_lives === 0) {
	var go = document.getElementById("gameover");
	go.style.display = "none";
	if (_goupdate != null) clearTimeout(_goupdate);
	init();
      }
  }
}

function keyup(e) {
  switch(e.keyCode) {
    case 65:
    case 68:
      _ship.rotating = 0;
      break;
    case 87:
      _ship.thrusting = false;
      break;
    case 32:
      _ship.firing = false;
      break;
  }
}
