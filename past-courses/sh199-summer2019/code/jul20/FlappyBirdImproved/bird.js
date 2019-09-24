class Bird {

    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.v = 0;
        this.a = 0.5;
        this.angle = 0;
        this.upforce = -2;
        this.flap = false;
        this.img = getImage("resources/bird.jpg");
    }

    draw(ctx) {
        ctx.save();
        ctx.translate(this.x, this.y);
        ctx.rotate(rad(this.angle));
        // ctx.arc(0, 0, 25, 0, Math.PI * 2);
        ctx.drawImage(this.img, -15, -15, 50, 30);
        ctx.restore();
    }

    update() {
        if(this.flap) {
          this.v += this.upforce;
          this.angle -= 10;
        } else {
          this.v += this.a;
          this.angle++;
        }

        this.v *= 0.95;
        this.y += this.v;
        if(this.angle < -30) {
          this.angle = -30;
        } else if(this.angle > 80) {
          this.angle = 80;
        }
    }

}
