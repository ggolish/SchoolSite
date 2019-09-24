var _ctx = document.getElementById("c").getContext("2d");
var _sb = document.getElementById("score").getContext("2d");
var _thrusting = false, _firing = false;
var _width = 1024, _height = 768;
var _score = 0, _lives = 20, _level = 0;
var _time = 0;
var _shippath = makeshippath();

function resize() {
  var c = document.getElementById("c");
  c.width = _width = window.innerWidth-5;
  c.height = _height = window.innerHeight-5;
}

function R(a, b) {
  var range = Math.abs(a-b)+1;
  var min = Math.min(a,b);
  return Math.floor(Math.random()*range) + min;
}

function dist(x1,y1,x2,y2) {
  var dx=x2-x1, dy=y2-y1;
  return dx*dx + dy*dy;
}

function start() {
  resize();
  _ship.reset();
  resetplayfield();
  update_scoreboard();
  update();
}

function gameover() {
  var g = document.getElementById("gameover");
  g.style.display = "block";
  g.style.top = ((_height/2) - (g.clientHeight/2)) + "px";
  g.style.left = ((_width/2) - (g.clientWidth/2)) + "px";
  goupdate();
}

function goupdate() {
  _ctx.clearRect(0,0,_width,_height);
  for(var r of _rocks) {
    r.update();
    r.draw();
  }
  setTimeout(goupdate, 16);
}

function resetplayfield() {
  _rocks = [];
  for(var i = 0; i < Math.min(5+_level, 10); i++)
    _rocks.push(new Rock());
  _ship.invulnerable = 180;
  _level++;
}

function update() {
  _ctx.clearRect(0,0,_width,_height);
  _time--;

  _ship.update();
  for(var i = 0; i < _rocks.length; i++) {
    _rocks[i].update();
    if (_ship.hit(_rocks[i])) {
      _lives--;
      update_scoreboard();
      if (_lives == 0) return gameover();
      _ship.reset();
    }
  }
  for(var i = 0; i < _bullets.length;) {
    var b = _bullets[i];
    b.update();
    if (b.lifetime < 0) {
      _bullets.splice(i,1);
      continue;
    }
    var dontdraw = false;
    for(var j in _rocks) {
      if (_rocks[j].hit(b.x, b.y)) {
	var r = _rocks[j];
	for(var k = 0; k < _nr[r.scale]; k++) {
	  _rocks.push(new Rock(r));
	}
	_rocks.splice(j, 1);
	_bullets.splice(i, 1);
	_score += _rs[r.scale];
	update_scoreboard();
	dontdraw = true;
      }
    }
    if (dontdraw) continue;
    _bullets[i].draw();
    i++;
  }
  if (_rocks.length == 0) resetplayfield();
  for(var r of _rocks) r.draw();
  _ship.draw();
  setTimeout(update, 16);
}

function update_scoreboard() {
  _sb.clearRect(0,0,320,200);
  _sb.fillStyle = "black";
  _sb.font = "36pt Arial";
  var s = "00000".substr(0,5-_score.toString().length) + _score;
  _sb.fillText(s, 25, 50);
  if (_lives > 5) {
    drawship(_sb, 40, 80, Math.PI/2);
    _sb.fillText("x " + _lives.toString(), 70, 100);
  } else {
    for(var i = 0; i < _lives; i++) {
      console.log("drawship %d", i);
      drawship(_sb, 40+(i*30), 80, Math.PI/2);
    }
  }
}

function keydown(e) {
  console.log(e.key);
  switch(e.key) {
    case 'ArrowUp':
    case 'w':
      _thrusting = true;
      break;
    case 'ArrowDown':
    case 's':
      break;
    case 'ArrowLeft':
    case 'a':
      _ship.da = -5 * Math.PI/180;
      break;
    case 'ArrowRight':
    case 'd':
      _ship.da = 5 * Math.PI/180;
      break;
    case ' ':
      _firing = true;
      break;
  }
}
function keyup(e) {
  switch(e.key) {
    case 'ArrowUp':
    case 'w':
      _thrusting = false;
      break;
    case 'ArrowDown':
    case 's':
      break;
    case 'ArrowLeft':
    case 'ArrowRight':
    case 'a':
    case 'd':
      _ship.da = 0;
      break;
    case ' ':
      _firing = false;
      break;
  }
}
