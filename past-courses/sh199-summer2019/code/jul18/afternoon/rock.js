var _rocks = [];
var _nr = [0, 0, 3, 2];
var _rs = [0, 100, 50, 25];

function Rock(def) {
  var scalar = [1.0, 1.0, 0.8, 0.6];

  if (typeof def == "object") {
    this.x = Math.floor(def.x);
    this.y = Math.floor(def.y);
    this.scale = def.scale-1;
  } else {
    do {
      this.x = R(0,_width);
      this.y = R(0,_height);
    } while (dist(this.x,this.y,_ship.x,_ship.y) < 1000);
    this.scale = 3;
  }
  this.angle = 0;
  this.spin = scalar[this.scale] * (R(-5,5)*Math.PI)/180;
  this.dx = ((Math.random()*10)-5) * scalar[this.scale];
  this.dy = ((Math.random()*10)-5) * scalar[this.scale];

  this.radius = 0;
  this.points = [];
  for(var i=0; i < 16; i++) {
    this.points[i] = Math.floor(Math.random()*8)+16;
    this.radius = Math.max(this.radius, this.points[i]);
  }
  this.radius *= this.scale;
  this.radiusq = this.radius * this.radius;

  this.lx = this.x - this.radius;
  this.ly = this.y - this.radius;
  this.gx = this.x + this.radius;
  this.gy = this.y + this.radius;

  this.draw = function() {
    _ctx.strokeStyle = "black";
    _ctx.lineWidth = 2;
    _ctx.save();
    _ctx.translate(this.x,this.y);
    this.angle = (this.angle + this.spin) % (Math.PI*2);
    _ctx.rotate(this.angle);
    _ctx.scale(this.scale, this.scale);
    _ctx.beginPath();
    for(var i = 0; i < 16; i++) {
      if (i) _ctx.lineTo(this.points[i],0);
      else _ctx.moveTo(this.points[i],0);
      _ctx.rotate((Math.PI*2)/this.points.length);
    }
    _ctx.closePath();
    _ctx.restore();
//    _ctx.moveTo(this.x+this.radius, this.y);
//    _ctx.arc(this.x, this.y, this.radius, 0, 360);
    _ctx.stroke();
  };

  this.update = function() {
    this.x = this.x + this.dx;
    if (this.x <= -20) this.x = _width+20;
    else if (this.x > _width+20) this.x = -20;
    this.y = this.y + this.dy;
    if (this.y <= -20) this.y = _height+20;
    else if (this.y > _height+20) this.y = -20;

    this.lx = this.x - this.radius;
    this.ly = this.y - this.radius;
    this.gx = this.x + this.radius;
    this.gy = this.y + this.radius;
//    this.angle = this.angle + this.spin;
  };
  this.hit = function(x, y) {
    if (x < this.lx || x > this.gx) return false;
    if (y < this.ly || y > this.gy) return false;
    if (dist(x,y, this.x,this.y) <= this.radiusq) return true;
    return false;
  };
}
