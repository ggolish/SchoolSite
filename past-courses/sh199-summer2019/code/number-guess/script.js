
let answer;

const KEY_ENTER = 13;

function gameStart() {
  answer = Math.floor(Math.random() * 101);
  setStatus("Guess a number between 0 and 100.");
}

function setStatus(status) {
  let e = document.querySelector("#game-status");
  e.value = status;
}

function guess() {
  let e = document.querySelector("#guess");
  let guess = parseInt(e.value);
  e.value = "";
  if(isNaN(guess)) {
    return;
  }

  if(guess == answer) {
    setStatus("Correct, you win!");
    addGuess(guess + " (Answer)");
  } else if(guess < answer) {
    setStatus("Higher.");
    addGuess(guess + " (Higher)");
  } else {
    setStatus("Lower.");
    addGuess(guess + " (Lower)");
  }

}

function checkKey(event) {
  if(event.keyCode == KEY_ENTER) {
    guess();
  }
}

function addGuess(guess) {
  let ul = document.querySelector("#previous-guesses");
  let li = document.createElement("li");
  li.innerHTML = guess;
  ul.appendChild(li);
}
