
function ball(x, y, angle) {
  this.x = x;
  this.y = y;
  this.dx = 10 * Math.cos(angle);
  this.dy = 10 * Math.sin(angle);

  this.update = function() {
    this.x = this.x + this.dx;
    this.y = this.y + this.dy;
    if (this.x > 790 || this.x <= 0) this.dx = -this.dx;
    if (this.y <= 0) this.dy = -this.dy
    if (this.y >= 550 && this.x >= _paddle_xpos && this.x <= _paddle_xpos+100) this.dy = -this.dy;
    if (this.y > 600) {
      // fix me
    }
  };

  this.draw = function() {
    _ctx.fillStyle="black";
    _ctx.fillRect(this.x, this.y, 10, 10);
  };
}
