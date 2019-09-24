class Bird {

    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.v = 0;
        this.a = 0.5;
        this.upforce = -15  ;
    }

    draw(ctx) {
        ctx.save();
        ctx.translate(this.x, this.y);
        // ctx.arc(0, 0, 25, 0, Math.PI * 2);
        ctx.fillStyle = "yellow";
        ctx.fillRect(-15, -15, 30, 30);
        ctx.restore();
    }

    update() {
        this.v += this.a;
        this.v *= 0.95;
        this.y += this.v;
    }

    fly() {
        this.v += this.upforce;
    }
}
