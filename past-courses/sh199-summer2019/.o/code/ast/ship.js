var _bullets = [];

function Ship(x, y, angle, ctx) {
  this.ctx = ctx;
  this.x = x;
  this.y = y;
  this.angle = angle;
  this.rotating = 0;
  this.thrusting = false;
  this.dx = 0;
  this.dy = 0;
  this.lastfire = -8;
  this.firing = false;
  this.invulnerable = 60;

  this.reset = function() {
    this.invulnerable = 60;
    this.angle = 0;
    this.rotating = 0;
    this.thrusting = false;
    this.x = _width/2;
    this.y = _height/2;
    this.dx = 0;
    this.dy = 0;
    this.lastfire = -8;
    this.firing = false;
  };

  this.drawship = function() {
    this.ctx.save();
    this.ctx.strokeStyle = "black";
    this.ctx.lineWidth = 2;
    this.ctx.translate(this.x,this.y);
    this.ctx.rotate(this.angle);

    this.ctx.beginPath();
    this.ctx.moveTo(20,0);
    this.ctx.lineTo(-20,10);
    this.ctx.lineTo(-16,7);
    this.ctx.lineTo(-16,-7);
    this.ctx.lineTo(-20,-10);
    this.ctx.closePath();
    this.ctx.stroke();

    if (this.thrusting) {
      this.ctx.strokeStyle = "red";
      this.ctx.beginPath();
      this.ctx.moveTo(-18,6);
      this.ctx.lineTo(-35,0);
      this.ctx.lineTo(-18,-6);
      this.ctx.moveTo(-18,6);
      this.ctx.closePath();
      this.ctx.stroke();
    }
    this.ctx.restore();
  };
  
  this.update = function() {
    if (this.invulnerable) this.invulnerable--;
    if (this.rotating) {
      this.angle=(this.angle+this.rotating)%(Math.PI*2);
      if (this.angle < 0) this.angle = Math.PI*2;
    }
    if (this.thrusting) {
      this.dx += 0.15 * Math.cos(this.angle);
      this.dy += 0.15 * Math.sin(this.angle);
    } else {
      this.dx *= 0.997;
      this.dy *= 0.997;
    }
    if (this.dx || this.dy) {
      this.x = (this.x+this.dx) % _width;
      this.y = (this.y+this.dy) % _height;
      if (this.x < 0) this.x = _width;
      if (this.y < 0) this.y = _height;
    }
    if (this.firing) {
      if (this.lastfire+8 < _time && _bullets.length < 15) {
	var b = new Bullet(this.x, this.y, this.angle, 10);
	_bullets.push(b);
	this.lastfire = _time;
      }
    }
    this.drawship();
  };

  this.hit = function(r) {
    if (this.invulnerable) return false;
    if (fdist(this.x,this.y, r.x,r.y) <= 225+r.radiusq) return true;
    return false;
  };
}

function Bullet(x, y, angle, offset) {
  var c = Math.cos(angle);
  var s = Math.sin(angle);

  this.x = x + c*offset;
  this.y = y + s*offset;
  this.angle = angle;
  this.dx = c*8.0;
  this.dy = s*8.0;
  this.lifetime = Math.min(_width, _height) * 0.85;
  this.draw = function() {
    _ctx.beginPath();
    _ctx.fillStyle = "black";
    _ctx.arc(this.x,this.y, 2, 0, 360);
    _ctx.closePath();
    _ctx.fill();
  };
  this.update = function() {
    this.x = (this.x + this.dx) % _width;
    this.y = (this.y + this.dy) % _height;
    if (this.x < 0) this.x = _width;
    if (this.y < 0) this.y = _height;
    this.lifetime -= 8.0;
  };
}

