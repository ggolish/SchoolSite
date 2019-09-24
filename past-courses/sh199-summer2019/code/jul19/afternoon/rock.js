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

  // Defines the drawing path for the rock:
  this.path = new Path2D();
  var angle = 0;
  for(var i=0; i < 16; i++) {
    var r = Math.floor(Math.random()*8)+16;
    var x = r * Math.cos(angle);
    var y = r * Math.sin(angle);
    if (i) this.path.lineTo(x,y);
    else this.path.moveTo(x,y);
    this.radius = Math.max(this.radius, r);
    angle += Math.PI/8;
  }
  this.path.closePath();

  this.draw = function() {
    _ctx.strokeStyle = "black";
    _ctx.lineWidth = 2;
    _ctx.save();
    _ctx.translate(this.x,this.y);
    this.angle = (this.angle + this.spin) % (Math.PI*2);
    _ctx.rotate(this.angle);
    _ctx.scale(this.scale, this.scale);
    _ctx.stroke(this.path);
    _ctx.restore();
  };

  this.update = function() {
    this.x = this.x + this.dx;
    if (this.x <= -20) this.x = _width+20;
    else if (this.x > _width+20) this.x = -20;
    this.y = this.y + this.dy;
    if (this.y <= -20) this.y = _height+20;
    else if (this.y > _height+20) this.y = -20;
  };

  // Uses the drawing path to determine if the bullet is inside of the path:
  this.hit = function(x, y) {
    _ctx.save();
    _ctx.translate(this.x,this.y);
    _ctx.rotate(this.angle);
    _ctx.scale(this.scale, this.scale);
    var flag = false;
    if (_ctx.isPointInPath(this.path, x, y)) flag = true;
    _ctx.restore();
    return flag;
  };
}
