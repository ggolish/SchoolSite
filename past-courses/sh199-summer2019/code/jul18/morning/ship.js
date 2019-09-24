
class Ship {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.angle = 0;

        // Physics variables
        this.v_x = 0;
        this.v_y = 0;
        this.a_x = 0;
        this.a_y = 0;

        // Sprite sheet
        this.image = resourceMap["resources/ship_sprite_sheet.png"];

        // State variables
        this.rotating = 0;
        this.moving = false;
        this.breaking = false;
    }

    draw(ctx) {
        ctx.save();
        ctx.translate(this.x, this.y);
        ctx.rotate(rad(this.angle));

        ctx.drawImage(this.image, -16, -16)
        ctx.drawImage(this.image, 0, 0, 32, 32, -16, -16, 32, 32);

        // ctx.strokeStyle = "rgb(255, 255, 255)";
        // ctx.beginPath();
        // ctx.moveTo(25, 0);
        // ctx.lineTo(-15, -15);
        // ctx.lineTo(-10, -5);
        // ctx.lineTo(-10, 5);
        // ctx.lineTo(-15, 15);
        // ctx.closePath();
        // ctx.stroke();
        //
        // if(this.moving) {
        //     ctx.beginPath();
        //     ctx.fillStyle = "red";
        //     ctx.moveTo(-10, -5);
        //     ctx.lineTo(-25, 0);
        //     ctx.lineTo(-10, 5);
        //     ctx.fill();
        // }

        ctx.restore();
    }

    update() {
        this.angle += 5 * this.rotating;

        // Move the ship if necessary
        let r = rad(this.angle);
        if(this.moving == true) {
            this.a_x = 0.1 * Math.cos(r);
            this.a_y = 0.1 * Math.sin(r);
        }
        this.v_x = this.v_x + this.a_x;
        // this.v_y += this.a_y
        this.v_y = this.v_y + this.a_y;
        this.x = this.x + this.v_x;
        this.y = this.y + this.v_y;

        this.a_x = 0;
        this.a_y = 0;

        if(this.breaking) {
            this.v_x += 0.05 * Math.cos(r + Math.PI);
            this.v_y += 0.05 * Math.sin(r + Math.PI);
        }
    }

    shoot() {
        return new Bullet(this.x, this.y, this.angle);
    }
}

function rad(angle) {
    return angle * Math.PI / 180.0 ;
}
