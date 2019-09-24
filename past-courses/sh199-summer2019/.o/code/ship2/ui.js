var _ctx;
var _ship1, _ship2;
var _bullets = [];

function setup() {
  _ctx = document.getElementById("c").getContext("2d");
  _ship1 = new ship(50,500,"black");
  _ship2 = new ship(750,500,"cyan");
  update();
}

function update(ev) {
  _ctx.clearRect(0,0,800,600);

  _ship1.update();
  _ship2.update();
  _ship1.draw();
  _ship2.draw();

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
      _ship1.thrusting = true;
      break;
    case 38: // up arrow
      _ship2.thrusting = true;
      break;
    case 83: // s
      _ship1.teleport();
      break;
    case 40: // down arrow
      _ship2.teleport();
      break;
    case 32: // space
      _ship1.firing = true;
      break;
    case 13: // enter
      _ship2.firing = true;
      break;
    case 65: // a
      _ship1.rotating = - Math.PI/24;
      break;
    case 37: // left
      _ship2.rotating = - Math.PI/24;
      break;
    case 68: // d
      _ship1.rotating = Math.PI/24;
      break;
    case 39: // right
      _ship2.rotating = Math.PI/24;
      break;
  }
}

function keyup(ev) {
  switch(ev.keyCode) {
    case 87: // w
      _ship1.thrusting = false;
      break;
    case 38: // up arrow
      _ship2.thrusting = false;
      break;
    case 83: // s
    case 40: // down arrow
      break;
    case 32:
      _ship1.firing = false;
      break;
    case 13:
      _ship2.firing = false;
      break;
    case 65: // a
    case 68: // d
      _ship1.rotating = 0;
      break;
    case 37: // left
    case 39: // right
      _ship2.rotating = 0;
      break;
  }
}
