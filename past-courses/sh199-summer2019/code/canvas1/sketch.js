
let canvas;
let ctx;

function startGame() {
    canvas = document.getElementById("canvas");
    ctx = canvas.getContext("2d");

    // Fill the backround with black
    ctx.fillStyle = "rgb(0, 0, 0)";
    ctx.fillRect(0, 0, canvas.width, canvas.height);

    // Draws my red box
    ctx.fillStyle = "rgb(255, 0, 0)";
    ctx.fillRect(10, 15, 100, 100);
}
