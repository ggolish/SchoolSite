class Pipe {

    constructor(width, height) {
        this.width = width;
        this.height = height;
        this.x = width +   50;
        this.y1 = Math.random() * height;
        this.y2 = Math.random() * height + this.y1 + 50;
    }

    draw(ctx) {
        ctx.fillStyle = "green";
        ctx.fillRect(this.x, 0, 50, this.y1);
        ctx.fillRect(this.x, this.y2, 50, this.height - this.y2);
    }

    update() {
        this.x -= 2  ;
    }

}
