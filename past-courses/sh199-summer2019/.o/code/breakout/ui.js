var _paddle_xpos = 0;
var _canvas, _ctx;
var _ball = null;

function setup() {
  _canvas = document.getElementById("c");
  _ctx = _canvas.getContext("2d");
  update();
}

function update() {
  _ctx.clearRect(0,0,800,600);

  _ctx.fillStyle = "red";
  _ctx.fillRect(_paddle_xpos, 550, 100, 25);

  if (_ball != null) {
    _ball.update();
    if (_ball.y > 600) {
      _ball = null;
    } else _ball.draw();
  }
  setTimeout(update, 16);
}

function offsets(e) {
  var top = 0, left = 0;
  while (e) {
    top = top + e.offsetTop;
    left = left + e.offsetLeft;
    e = e.offsetParent;
  }
  return {xo: left, yo: top};
}

function mmove(ev) {
  var off = offsets(_canvas);
  _paddle_xpos = (ev.clientX - off.xo) -50 ;
  if (_paddle_xpos < 0) _paddle_xpos = 0;
  if (_paddle_xpos > 700) _paddle_xpos = 700;
}

function serve(ev) {
  if (_ball == null) {
    var off = offsets(_canvas);
    var bx = (ev.clientX - off.xo);
    if (bx < 0) bx = 0;
    if (bx > 700) bx = 700;
    _ball = new ball(bx, 540, -Math.PI/4);
    console.log(_ball);
  }
}