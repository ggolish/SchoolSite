
let ctx, canvas;
let bird;
let pipes = [];
let frameCount = 0;
let nextPipe = Math.floor(Math.random() * 100) + 150;
let nextFrame = false;

document.body.onload = function() {
    setup();
    draw();
}

document.body.onkeydown = processKeyDown;

function setup() {
    canvas = document.getElementById("canvas");
    ctx = canvas.getContext("2d");
    bird = new Bird(50, canvas.height / 2);
    pipes.push(new Pipe(canvas.width, canvas.height));
}

function draw() {
    frameCount += 1;
    ctx.fillStyle = "black";
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    bird.draw(ctx);

    for(let p of pipes) {
        p.draw(ctx);
    }

    update();
    window.requestAnimationFrame(draw);
}

function update() {
    bird.update();
    constrainToScreen(bird);

    for(let p of pipes) {
        p.update();
    }

    if(frameCount % nextPipe == 0) {
        if(nextFrame == false) {
            nextFrame = true;
        } else {
            nextPipe = Math.floor(Math.random() * 50) + 75;
            pipes.push(new Pipe(canvas.width, canvas.height));
            nextFrame = false;
        }
    }
}

function constrainToScreen(obj) {
    if(obj.y <= 0) {
        obj.y = 0;
    }

    if(obj.y >= canvas.height) {
        obj.y = canvas.height;
    }
}

function processKeyDown(event) {
    if(event.keyCode == 32) {
        bird.fly();
    }
}
