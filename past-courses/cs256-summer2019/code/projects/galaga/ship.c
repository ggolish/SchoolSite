#include <ncurses.h>
#include <stdlib.h>

#include "ship.h"

ship_t *new_ship(int x, int y)
{
  ship_t *s;

  s = malloc(sizeof(ship_t));
  s->x = x;
  s->y = y;

  return s;
}

void draw_ship(ship_t *s)
{
  attron(A_BOLD);
  mvaddch(s->y, s->x, 'S');
  attroff(A_BOLD);
}

bullet_t *shoot(ship_t *s)
{
  bullet_t *b = new_bullet(s->x, s->y - 1);
  return b;
}
