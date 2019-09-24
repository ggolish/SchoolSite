
class Ship {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.angle = 0;

        // State variables
        this.rotating = 0;
    }

    draw(ctx) {
        ctx.save();
        ctx.translate(this.x, this.y);
        ctx.rotate(this.angle * Math.PI / 180);
        ctx.strokeStyle = "rgb(255, 255, 255)";
        ctx.beginPath();
        ctx.moveTo(35, 0);
        ctx.lineTo(-20, -15);
        ctx.lineTo(-10, 0);
        ctx.lineTo(-20, 15);
        ctx.closePath();
        ctx.stroke();
        ctx.restore();
    }

    update() {
        this.angle += 10 * this.rotating;
    }
}
