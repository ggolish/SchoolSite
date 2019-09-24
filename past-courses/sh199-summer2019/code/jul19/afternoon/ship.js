function drawship(ctx, x, y, rot) {
  ctx.lineWidth = 3;
  ctx.save();
  ctx.translate(x,y);
  ctx.rotate(rot);
  ctx.stroke(_shippath);
  if (ctx != _ctx) ctx.restore();
}

function makeshippath() {
  var path = new Path2D();
  path.moveTo(20,0);
  path.lineTo(-20,10);
  path.lineTo(-16,7);
  path.lineTo(-16,-7);
  path.lineTo(-20,-10);
  path.closePath();
  return path;
}

var _ship = {
  x : 0,
  y : 0,
  dx : 0,
  dy : 0,
  angle : 0,
  da : 0,
  invulnerable : 180,

  reset : function() {
    this.x = _width/2;
    this.y = _height/2;
    this.dx = this.dy = this.da = 0;
    this.angle = 0;
    this.da = 0;
    this.invulnerable = 180;
  },

  draw : function() {
    _ctx.strokeStyle = (this.invulnerable? "blue" : "black");
    drawship(_ctx, this.x,this.y,this.angle);
    if (_thrusting) {
      _ctx.strokeStyle = "red";
      _ctx.beginPath();
      _ctx.moveTo(-18,6);
      _ctx.lineTo(-35,0);
      _ctx.lineTo(-18,-6);
      _ctx.moveTo(-18,6);
      _ctx.closePath();
      _ctx.stroke();
    }
    _ctx.restore();
  },

  update : function() {
    if (this.invulnerable > 0) this.invulnerable--;
    if (_thrusting) {
      this.dy += .15 * Math.sin(this.angle);
      this.dx += .15 * Math.cos(this.angle);
    } else {
      this.dx *= .997;
      this.dy *= .997;
    }
    this.x = this.x + this.dx;
    if (this.x <= -20) this.x = _width+20;
    else if (this.x > _width+20) this.x = -20;
    this.y = this.y + this.dy;
    if (this.y <= -20) this.y = _height+20;
    else if (this.y > _height+20) this.y = -20;
    this.angle = this.angle + this.da;
    if (_firing) {
      if (_time <= 0) {
	var b = new Bullet(this.x, this.y, this.angle, 20);
	_bullets.push(b);
	_time = 8;
      }
    }
  },

  hit : function(r) {
    if (this.invulnerable > 0) return false;
    var rad = 20, t = Math.PI + Math.atan(.5);
    var x = rad * Math.cos(this.angle);
    var y = rad * Math.sin(this.angle);
    if (r.hit(this.x + x,this.y + y)) return true;
    rad = Math.sqrt(500);
    x = rad * Math.cos(this.angle+t);
    y = rad * Math.sin(this.angle+t);
    if (r.hit(this.x + x,this.y + y)) return true;
    x = rad * Math.cos(this.angle-t);
    y = rad * Math.sin(this.angle-t);
    if (r.hit(this.x + x,this.y + y)) return true;
  }
};
