class Pipe {

    constructor(width, height) {
        this.width = width;
        this.height = height;
        this.x = width + 50;
        this.y1 = randRange(0, height - 100);
        this.y2 = randRange(this.y1 + 100, height);
        this.color = "green";
    }

    draw(ctx) {
        ctx.fillStyle = this.color;
        ctx.fillRect(this.x, 0, 50, this.y1);
        ctx.fillRect(this.x, this.y2, 50, this.height - this.y2);
    }

    update() {
        this.x -= 2  ;
    }

    hits(bird) {
      if(bird.x >= this.x && bird.x <= this.x + 50) {
        if(bird.y <= this.y1 || bird.y >= this.y2) {
          this.color = "red";
          return true;
        }
      }
      this.color = "green";
      return false;
    }

    offscreen() {
      return (this.x < -50);
    }
}
