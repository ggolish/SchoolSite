var _ctx, _canvas, _off, _countdown = 1, _maxlength = 1000;

var _mx = 0, _my = 0;
var _body = [];
var _food = [];

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
  _mx = ev.clientX - _off.xo;
  _my = ev.clientY - _off.yo;
}

function setup() {
  _canvas = document.getElementById("c");
  _ctx = _canvas.getContext("2d");
  _off = offsets(_canvas);
  for(var i = 0; i < 10; i++) {
    _body.push({x:512+i*5, y:384});
  }
  for(var i = 0 ; i < 10000; i++) {
    _food.push({x:(Math.random()*5000)-2500, y:(Math.random()*5000)-2500});
  }
  update();
}

function update() {
  _ctx.clearRect(0,0,1024, 768);

  _ctx.fillStyle = "red";
  _ctx.strokeStyle = "black";
  
  if (_countdown-- == 0) {
    var x = _mx - 512;
    var y = _my - 384;
    var angle = Math.atan2(y,x);
    var dx = 5*Math.cos(angle);
    var dy = 5*Math.sin(angle);
    _body.unshift({x:_body[0].x+dx, y:_body[0].y+dy});
    if (_body.length > _maxlength) _body.pop();
    _countdown = 1;
  }

   _ctx.save();
   var tx = 497-_body[0].x;
   var ty = 369-_body[0].y;
   _ctx.translate(tx, ty);
  for(var i = _body.length-1; i >= 0; i--) {
    if (_body[i].x+tx > 1039 || _body[i].x+tx < -15) continue;
    if (_body[i].y+ty > 783 || _body[i].y+ty < -15) continue;
    _ctx.beginPath();
    _ctx.arc(_body[i].x,_body[i].y, 15, 0, Math.PI*2);
    _ctx.closePath();
    _ctx.fill();
    _ctx.stroke();
//    _ctx.fillRect(_body[i].x, _body[i].y, 30, 30);
//    _ctx.strokeRect(_body[i].x, _body[i].y, 30, 30);
  }
  _ctx.fillStyle = "green";
  for(var i = 0; i < _food.length; i++) {
    if (_food[i].x+tx > 1039 || _food[i].x+tx < -15) continue;
    if (_food[i].y+ty > 783 || _food[i].y+ty < -15) continue;
    _ctx.beginPath();
    _ctx.arc(_food[i].x,_food[i].y, 5, 0, Math.PI*2);
    _ctx.fill();
    _ctx.closePath();
  }
  _ctx.restore();
  setTimeout(update, 16);
}
