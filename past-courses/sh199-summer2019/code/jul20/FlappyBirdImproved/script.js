
let ctx, canvas;
let bird;
let pipes = [];
let frameCount = 0;
let nextPipe = Math.floor(randRange(75, 150));
let nextFrame = false;
let background;
let score = 0;
let hitting = null;

document.getElementById("start-button").onclick = startGame;

async function startGame(event) {
    event.target.style.display = "none";
    await setup();
    draw();
}

document.body.onkeydown = processKeyDown;
document.body.onkeyup = processKeyUp;

async function setup() {
    canvas = document.getElementById("canvas");
    ctx = canvas.getContext("2d");
    await loadImages([
      "resources/bird.jpg",
      "resources/background.png"
    ]);
    background = getImage("resources/background.png");
    bird = new Bird(50, canvas.height / 2);
    pipes.push(new Pipe(canvas.width, canvas.height));
}

function draw() {
    frameCount += 1;
    ctx.drawImage(background, 0, 0);

    bird.draw(ctx);

    for(let p of pipes) {
        p.draw(ctx);
    }

    displayScore();

    update();
    window.requestAnimationFrame(draw);
}

function displayScore() {
  ctx.font = "30px Consolas";
  ctx.fillStyle = "yellow";
  ctx.fillText(score.toString(), 25, 40);
}

function update() {
    bird.update();
    constrainToScreen(bird);

    let deadPipes = [];
    for(let p of pipes) {
        p.update();
        if(p.hits(bird)) {
          if(hitting != p) {
            score -= 5;
            hitting = p;
          }
        } else if(p.offscreen()) {
          score += 1;
          deadPipes.push(pipes.indexOf(p));
        }
    }

    for(let i of deadPipes) {
      pipes.splice(i, 1);
    }

    if(frameCount % nextPipe == 0) {
        if(nextFrame == false) {
            nextFrame = true;
        } else {
            nextPipe = Math.floor(randRange(75, 150));
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
        bird.flap = true;
    }
}

function processKeyUp(event) {
    if(event.keyCode == 32) {
        bird.flap = false;
    }
}
