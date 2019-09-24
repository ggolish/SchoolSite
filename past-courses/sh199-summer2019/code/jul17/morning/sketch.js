
//Constants
const KEY_UP = 38;
const KEY_DOWN = 40;
const KEY_LEFT = 37;
const KEY_RIGHT = 39;
const KEY_SPACE = 32;

let canvas;
let ctx;

let ship;
let bullets = [];

// Event handling
document.body.onload = setup;
document.body.onkeydown = processKeyDown;
document.body.onkeyup = processKeyUp;
document.getElementById("start-button").onclick = function(event) {
    event.target.style.display = "none";
    draw();
};

function setup() {
    canvas = document.getElementById("asteroids-canvas");
    ctx = canvas.getContext("2d");

    // Create a Ship
    ship = new Ship(canvas.width / 2, canvas.height / 2);
}

function draw() {
    // Clear the previous frame
    ctx.fillStyle = "rgb(0, 0, 0)";
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    // Draw the ship
    ship.draw(ctx);

    update();
    window.requestAnimationFrame(draw);
}

function update() {
    ship.update();
}

function processKeyDown(event) {
    if(event.keyCode == KEY_LEFT) {
        ship.rotating = -1;
    } else if(event.keyCode == KEY_RIGHT) {
        ship.rotating = 1;
    } else if(event.keyCode == KEY_UP) {
        ship.moving = true;
    } else if(event.keyCode == KEY_DOWN) {
        ship.breaking = true;
    } else if(event.keyCode == KEY_SPACE) {
        ship.shoot();
    }
}

function processKeyUp(event) {
    if(event.keyCode == KEY_LEFT) {
        ship.rotating = 0;
    } else if(event.keyCode == KEY_RIGHT) {
        ship.rotating = 0;
    } else if(event.keyCode == KEY_UP) {
        ship.moving = false;
    } else if(event.keyCode == KEY_DOWN) {
        ship.breaking = false;
    }
}
