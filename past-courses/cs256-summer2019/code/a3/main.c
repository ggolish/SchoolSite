#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Forward declaration for rand_range function, so that main won't get confused
int rand_range(int min, int max);
int guess_game(int answer, int max_guesses, int min, int max);

// The first command line argument is the max # of guesses,
// the second and third are the min and max of range respectively
int main(int argc, char *argv[])
{
  // Checking if the proper number of command line args have been passed
  if(argc != 4) {
    fprintf(stderr, "Usage: %s <max-guesses> <min> <max>\n", argv[0]);
    exit(1);
  }

  // Parsing command line args as ints
  int max_guesses = atoi(argv[1]);
  int min = atoi(argv[2]);
  int max = atoi(argv[3]);

  // Choose number and seed random number generator
  srand(time(NULL));


  char c[10];
  c[0] = '\0';

  while(c[0] != 'n') {
    int answer = rand_range(min, max);  
    int winlose = guess_game(answer, max_guesses, min, max);
    if(winlose == 1) {
      printf("You win.\n");
    } else {
      printf("You lose. The answer is %d\n", answer);
    }
    printf("Would you like to play again? ");
    scanf("%s", c);
    printf("\n");
  }

  printf("Goodbye\n");

  return 0;
}

// Produces a random number in a specified range
// Source: https://www.geeksforgeeks.org/generating-random-number-range-c/
int rand_range(int min, int max)
{
  return (rand() % (max - min + 1)) + min;
}

int guess_game(int answer, int max_guesses, int min, int max)
{
  int nguesses = 0, guess;

  // Game loop
  while(nguesses < max_guesses) {
    nguesses++;
    printf("Enter an integer between %d and %d: ", min, max);
    scanf("%d", &guess);

    // Check if they guessed correctly
    if(guess == answer) {
      // They guessed correctly and win
      return 1;
    } else if(guess < answer) {
      printf("Higher.\n");
    } else {
      printf("Lower.\n");
    }
  } 

  // They are out of guesses and they lose
  return -1;
}
