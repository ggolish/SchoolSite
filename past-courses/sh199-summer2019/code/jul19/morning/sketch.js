
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
let asteroids = [];

// Event handling
// document.body.onload = setup;
document.body.onkeydown = processKeyDown;
document.body.onkeyup = processKeyUp;
// document.getElementById("start-button").onclick = function(event) {
//     event.target.style.display = "none";
//     draw();
// };
document.getElementById("start-button").onclick = startGame;

async function startGame(event) {
    event.target.style.display = "none";
    await setup();
    draw();
}

async function setup() {
    canvas = document.getElementById("asteroids-canvas");
    ctx = canvas.getContext("2d");

    // Load my resources
    await loadImages([
        "resources/ship_sprite_sheet.png",
    ]);

    // Create a Ship
    ship = new Ship(canvas.width / 2, canvas.height / 2);
    for(let i = 0; i < 5; i++) {
        asteroids.push(new Asteroid(0, 0));
    }
}

function draw() {
    // Clear the previous frame
    ctx.fillStyle = "rgb(0, 0, 0)";
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    // Draw the bullets
    for(let b of bullets) {
        b.draw(ctx);
    }

    // Draw Asteroids
    for(let a of asteroids) {
        a.draw(ctx);
    }

    // Draw the ship
    ship.draw(ctx);

    update();
    window.requestAnimationFrame(draw);
}

function update() {
    ship.update();
    constrainToScreen(ship, 20);
    for(let b of bullets) {
        b.update();
    }
    for(let a of asteroids) {
        a.update();
        constrainToScreen(a, 40);
    }
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
        // The ship creates a new bullet object, and we store it in the global
        // bullets array
        let bullet = ship.shoot();
        bullets.push(bullet);
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

// Keeps an object (that has an x and y parameter) on the screen by wrapping it
function constrainToScreen(obj, offset) {
    // Creates a larger boundary to allow for seamless transition of object
    let min_x = -offset;
    let max_x = canvas.width + offset;
    let min_y = -offset;
    let max_y = canvas.height + offset;

    // Constraining the x axis of the object
    if(obj.x > max_x) {
        obj.x = min_x;
    } else if(obj.x < min_x) {
        obj.x = max_x;
    }

    // Constraining the y axis of the object
    if(obj.y > max_y) {
        obj.y = min_y;
    } else if(obj.y < min_y) {
        obj.y = max_y;
    }
}
