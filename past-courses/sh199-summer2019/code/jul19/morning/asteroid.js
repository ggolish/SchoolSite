class Asteroid {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.angle = Math.floor(Math.random() * 361) * Math.PI / 180;
        this.v_mag = Math.random() * 4 + 1;
        this.v_x = this.v_mag * Math.cos(this.angle);
        this.v_y = this.v_mag * Math.sin(this.angle);
    }

    draw(ctx) {
        ctx.save();
        ctx.translate(this.x, this.y);
        ctx.rotate(this.angle);
        ctx.beginPath();
        ctx.moveTo(-15, -15);
        ctx.lineTo(-15, 15);
        ctx.lineTo(15, 15);
        ctx.lineTo(15, -15);
        ctx.closePath();
        ctx.strokeStyle = "white";
        ctx.stroke();
        ctx.restore();
    }

    update() {
        this.x += this.v_x;
        this.y += this.v_y;
        this.angle += Math.PI / 180;
    }
}
