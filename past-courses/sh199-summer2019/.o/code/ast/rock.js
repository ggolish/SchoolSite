var _rocks = [];
var _scalar = [1.0, 1.0, 0.8, 0.6 ];

var r = new Rock();
r.draw();

function fdist(x1, y1, x2, y2) {
  var dx = x1-x2;
  var dy = y1-y2;
  return (dx*dx)+(dy*dy);
}

function Rock(def) {
  if (typeof def == "object") {
    this.x = Math.floor(def.x);
    this.y = Math.floor(def.y);
    this.scale = def.scale-1;
  } else {
    this.x = Math.floor(Math.random()*_width);
    this.y = Math.floor(Math.random()*_height);
    this.scale = 3;
  }
  this.angle = 0;
  this.spin = _scalar[this.scale] *
    ((Math.floor((Math.random()*10))-5)*Math.PI)/180;
  this.radius = 0;
  this.points = [];
  for(var i = 0; i < 16; i++) {
    this.points[i] = Math.floor(Math.random()*8)+16;
    this.radius = Math.max(this.radius, this.points[i]);
  }
  this.radius *= this.scale;
  this.radiusq = this.radius * this.radius;
  this.dx = ((Math.random()*10)-5) * _scalar[this.scale];
  this.dy = ((Math.random()*10)-5) * _scalar[this.scale];

  this.lx = this.x-this.radius;
  this.ly = this.y-this.radius;
  this.gx = this.x+this.radius;
  this.gy = this.y+this.radius;

  this.draw = function() {
    _ctx.save();
    _ctx.translate(this.x, this.y);
    _ctx.strokeStyle = "black";
    _ctx.rotate(this.angle);
    this.angle = (this.angle + this.spin) % (Math.PI*2);
    _ctx.scale (this.scale, this.scale);
    _ctx.beginPath();
    for(var i=0; i < this.points.length; i++) {
      if (i) _ctx.lineTo(this.points[i], 0);
      else _ctx.moveTo(this.points[i], 0);
      _ctx.rotate((Math.PI*2)/this.points.length);
    }
    _ctx.closePath();
    _ctx.stroke();
    _ctx.restore();
//     _ctx.strokeRect(this.lx,this.ly,this.radius*2,this.radius*2);
//     _ctx.moveTo(this.x+this.radius,this.y+this.radius);
//     _ctx.arc(this.x,this.y,this.radius, 0, 360);
    _ctx.stroke();
  };

  this.update = function() {
    this.x += this.dx;
    this.y += this.dy;
    if (this.x < -this.radius) this.x = _width+this.radius;
    if (this.y < -this.radius) this.y = _height+this.radius;
    if (this.x > _width+this.radius) this.x = -this.radius;
    if (this.y > _height+this.radius) this.y = -this.radius;
    this.lx = this.x-this.radius;
    this.ly = this.y-this.radius;
    this.gx = this.x+this.radius;
    this.gy = this.y+this.radius;
  };

  this.hit = function(x, y) {
    if (x < this.lx || x > this.gx) return false;
    if (y < this.ly || y > this.gy) return false;
    console.log(x, y, this.lx, this.ly, this.gx, this.gy);
    // replace with something better:
    if (fdist(x,y, this.x,this.y) <= this.radiusq) return true;
    return false;
  };
}
