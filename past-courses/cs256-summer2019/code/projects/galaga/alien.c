#include <ncurses.h>
#include <stdlib.h>

#include "alien.h"

alien_t *new_alien(int x, int y)
{
  alien_t *a;

  a = malloc(sizeof(alien_t));
  a->x = x;
  a->y = y;

  return a;
}

agroup_t *new_agroup()
{
  agroup_t *ag;

  ag = malloc(sizeof(agroup_t));

  ag->length = 0;
  for(int x = 1; x <= 4; ++x) {
    for(int y = 1; y <= 4; ++y) {
      ag->aliens[ag->length++] = new_alien(x, y);
    }
  }

  ag->state = RIGHT;

  return ag;
}

void draw_alien(alien_t *a)
{
  attron(A_BOLD);
  mvaddch(a->y, a->x, 'A');
  attroff(A_BOLD);
}

void draw_agroup(agroup_t *ag)
{
  for(int i = 0; i < ag->length; ++i) {
    draw_alien(ag->aliens[i]);
  }
}

bullet_t *alien_shoot(alien_t *a)
{
  bullet_t *b = new_bullet(a->x, a->y - 1);
  return b;
}

void update_aliens(agroup_t *aliens)
{
}

