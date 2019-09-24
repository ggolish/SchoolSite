class Bullet {
    constructor(x, y, angle) {
        this.x = x;
        this.y = y;
        this.angle = angle * Math.PI / 180;
    }

    draw(ctx) {
        ctx.save();
        ctx.translate(this.x, this.y);
        ctx.rotate(this.angle);
        ctx.beginPath();
        ctx.fillStyle = "white";
        ctx.moveTo(-10, -5);
        ctx.lineTo(-10, 5);
        ctx.lineTo(10, 5);
        ctx.lineTo(10, -5);
        ctx.closePath();
        ctx.fill();
        ctx.restore();
    }

    update() {
        this.x += 5 * Math.cos(this.angle);
        this.y += 5 * Math.sin(this.angle);
    }
}
