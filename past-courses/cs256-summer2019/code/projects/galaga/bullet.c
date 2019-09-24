#include <ncurses.h>
#include <stdlib.h>

#include "bullet.h"

bullet_t *new_bullet(int x, int y)
{
  bullet_t *b;

  b = malloc(sizeof(bullet_t));
  b->x = x;
  b->y = y;
  return b;
}

void draw_bullet(bullet_t *b)
{
  mvaddch(b->y, b->x, '*');
}

void update_bullet(bullet_t *b)
{
  b->y--;
}


