var _maze;

function dim(w, h) {
  var a = [];
  for(var i = 0 ; i < w; i++) {
    a[i] = [];
    for(var j = 0; j < h; j++)
      a[i][j] = 0;
  }
  return a;
}

function makemaze(x, y) {
  // 4 directions (right, up, left, down):
  var dx = [1, 0, -1, 0];
  var dy = [0, -1, 0, 1];

  // Pick a starting direction:
  var d = Math.floor(Math.random()*4);

  /**
   * Try to move in all four directions starting with the randomly picked
   * starting direction (d).  Blast a hole in the wall if there is an
   * as yet un-revealed space between this position and the direction being
   * looked at.  Call this function again at the new position.
   */
  for(var i = 0; i < 4; i++) {
    var mx = x + dx[d];
    var my = y + dy[d];
    var nx = x + 2 * dx[d];
    var ny = y + 2 * dy[d];
    if (nx > 0 && nx < _mwidth && ny > 0 && ny < _mheight) {
      if ((_maze[mx][my] == 0) && (_maze[nx][ny] == 0)) {
        _maze[mx][my] = _maze[nx][ny] = 1;
        makemaze(nx, ny);
      }
    }
    d = (d+1) % 4;
  }
}
