var _bullets = [];

function Bullet(x, y, angle, offset) {
  this.x = x + offset*Math.cos(angle);
  this.y = y + offset*Math.sin(angle);
  this.dx = 8 * Math.cos(angle);
  this.dy = 8 * Math.sin(angle);
  
  this.lifetime = Math.min(_width,_height) * 0.85;

  this.draw = function() {
    _ctx.beginPath();
    _ctx.fillStyle = "black";
    _ctx.arc(this.x, this.y, 2, 0, 360);
    _ctx.closePath();
    _ctx.fill();
  };

  this.update = function() {
    this.x = (this.x + this.dx) % _width;
    this.y = (this.y + this.dy) % _height;
    if (this.x < 0) this.x += _width;
    if (this.y < 0) this.y += _height;
    this.lifetime -= 8.0;
  };
}
