/**
 * Object constructor for the ship object:
 */
function ship(x, y, color) {
  // Ship properties:
  this.x = x;
  this.y = y;
  this.thrusting = false;
  this.rotating = 0;
  this.dx = 0;
  this.dy = 0;
  this.angle = 0;
  this.lives = 3;
  this.color = color;
  this.cooldown = 0;

  this.draw = function() {
    _ctx.strokeStyle = this.color;
    _ctx.lineWidth = 3;
    _ctx.save();
    _ctx.translate(this.x, this.y);
    this.angle = this.angle + this.rotating;
    _ctx.rotate(this.angle);
    _ctx.beginPath();
    _ctx.moveTo(-20,-10);
    _ctx.lineTo(20,0);
    _ctx.lineTo(-20,10);
    _ctx.closePath();
    _ctx.stroke();
    if (this.thrusting) {
      _ctx.strokeStyle = "red";
      _ctx.beginPath();
      _ctx.moveTo(-22, -8);
      _ctx.lineTo(-42, 0);
      _ctx.lineTo(-22, 8);
      _ctx.moveTo(-22, -8);
      _ctx.closePath();
      _ctx.stroke();
    }
    _ctx.restore();
  };

  this.update = function() {
    if (this.cooldown > 0) this.cooldown -= 1;
    else if (this.firing) {
      _bullets.push(new bullet(this.x,this.y,this.angle));
      this.cooldown = 8;
    }
    if (this.thrusting) {
      this.dx = this.dx + (.12 * Math.cos(this.angle));
      this.dy = this.dy + (.12 * Math.sin(this.angle));
    } else {
      this.dx = this.dx * .997;
      this.dy = this.dy * .997;
    }
    this.x = this.x + this.dx;
    this.y = this.y + this.dy;
    if (this.x > 800) this.x -= 800;
    if (this.x < 0) this.x += 800;
    if (this.y > 600) this.y -= 600;
    if (this.y < 0) this.y += 600;    
  };

  this.teleport = function() {
    this.x = Math.random() * 800;
    this.y = Math.random() * 600;
    this.dx = 0;
    this.dy = 0;
  };
}

function bullet(x, y, angle) {
  var c = Math.cos(angle), s = Math.sin(angle);
  this.x = x + (20*c);
  this.y = y + (20*s);
  this.dx = 5 * c;
  this.dy = 5 * s;
  this.lifetime = 500;

  this.draw = function() {
    _ctx.fillStyle = "black";
    _ctx.fillRect(this.x-1,this.y-1,3,3);
  };

  this.update = function() {
    this.lifetime -= 5;
    this.x = this.x + this.dx;
    this.y = this.y + this.dy;
    if (this.x > 800) this.x -= 800;
    if (this.x < 0) this.x += 800;
    if (this.y > 600) this.y -= 600;
    if (this.y < 0) this.y += 600;    
  };
}

