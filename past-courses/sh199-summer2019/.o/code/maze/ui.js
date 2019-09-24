
var _x, _y;
var _iconsize = 24;
var _wall, _player;
var _ctx;
var _totalimages = 0, _loadedimages = 0;

function imagecount(event) {
  _loadedimages += 1;
  if (_loadedimages == _totalimages) drawscreen();
}

function loadimage(src) {
  var img = new Image(name);
  img.onload = imagecount;
  img.src = src;
  _totalimages++;
  return img;
}

function setup() {
  _ctx = document.getElementById("maze").getContext("2d");
  _wall = loadimage("img/wall.png");
  _player = loadimage("img/man.png");

  _mwidth = 1024 / _iconsize;
  if (_mwidth % 2 == 0) _mwidth -= 1;
  _mheight = 768 / _iconsize;
  if (_mheight % 2 == 0) _mheight -= 1;

  _maze = dim(_mwidth, _mheight);
  makemaze(1,1);
  _x = 1;
  _y = 1;
}

function drawmaze()
{
  _ctx.clearRect(0,0,1024,768);
  for(var row = 0; row < _mheight; row++) {
    for(var col = 0; col < _mwidth; col++) {
      if (_maze[col][row] == 0) _ctx.drawImage(_wall, col*_iconsize, row*_iconsize)
    }
  }
}

function drawscreen() {
  drawmaze();
  _ctx.drawImage(_player, _x*_iconsize, _y*_iconsize);
}

function key(ev) {
  switch(ev.key) {
    case 'w': // w
     if (_maze[_x][_y-1]) _y -= 1;
     break;
    case 's': // s
     if (_maze[_x][_y+1]) _y += 1;
     break;
    case 'a': // a
     if (_maze[_x-1][_y]) _x -= 1;
     break;
    case 'd': // d
     if (_maze[_x+1][_y]) _x += 1;
     break;
  }
  drawscreen();
}
