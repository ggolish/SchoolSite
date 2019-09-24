#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

#include "galaga.h"
#include "ship.h"
#include "alien.h"

#define MAX_BULLETS 100

// The possible game states
typedef enum {
  PLAYING,
  FINISHED
} state_t;

// Global variables
typedef struct {
  int width, height;
  state_t state;
  ship_t *ship;
  bullet_t *bullets[MAX_BULLETS];
  int nbullets;
  agroup_t *ag;
} galaga_t;

// The game variable struct
galaga_t g;

void setup(int width, int height);
void draw();
void update();
void process_input();
double time_in_milli();

// Begin the game, contain the game loop
void start_game(int width, int height)
{
  setup(width, height);

  // The game loop, with code to control fps
  double start = time_in_milli();
  double dt;
  while(g.state != FINISHED) {
    dt = time_in_milli() - start;
    if(dt > 33) {
      draw();
      update();
      process_input();
      start = time_in_milli();
    }
  }
}

// Closes curses
void end_game()
{
  endwin();
}

void setup(int width, int height)
{
  // ----- NCURSES INIT ----- //
  initscr();            // Initialize ncurses library and clear the screen
  cbreak();             // Disable terminal buffering
  keypad(stdscr, true); // Enables special keyboard characters
  noecho();             // Disable the echoing of characters
  curs_set(false);      // Disable the cursor   
  timeout(false);       // Enable nonblocking input
  // ------------------------ //
  
  // ----- INIT GAME VARIABLES ----- //
  g.width = width;
  g.height = height;
  g.state = PLAYING;
  g.ship = new_ship(g.width / 2, g.height - 1);
  g.nbullets = 0;
  g.ag = new_agroup();
  // ------------------------------- //
}

void draw()
{
  clear();    // Clear the previous frame

  // Draw the ship
  draw_ship(g.ship);

  // Draw the bullets
  for(int i = 0; i < g.nbullets; ++i) {
    draw_bullet(g.bullets[i]);
  }

  // Draw aliens
  draw_agroup(g.ag);

  // Draw the game border
  mvhline(0, 1, '-', g.width); 
  mvvline(0, 0, '|', g.height + 1); 
  mvhline(g.height, 1, '-', g.width);
  mvvline(0, g.width, '|', g.height + 1);

  // Write the changes to the screen
  refresh();
}

void update()
{
  if(g.ship->x >= g.width) g.ship->x = g.width - 1;
  else if(g.ship->x <= 0) g.ship->x = 1;

  // Update the bullets
  for(int i = 0; i < g.nbullets; ++i) {
    update_bullet(g.bullets[i]);
    if(g.bullets[i]->y <= 0) {
      free(g.bullets[i]);
      g.bullets[i] = g.bullets[--g.nbullets];
    }
  }
}

void process_input()
{
  int c = getch();

  switch(c) {
    case KEY_LEFT:
      g.ship->x--;
      break;
    case KEY_RIGHT:
      g.ship->x++;
      break;
    case ' ':
      if(g.nbullets < MAX_BULLETS) {
        bullet_t *b = shoot(g.ship);
        g.bullets[g.nbullets++] = b;
      }
      break;
  }
}

double time_in_milli()
{
  return (clock() / (double)CLOCKS_PER_SEC) * 1000.0;
}

