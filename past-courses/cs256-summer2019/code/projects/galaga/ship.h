#ifndef SHIP_H_
#define SHIP_H_

#include "bullet.h"

typedef struct {
  int x;
  int y;
} ship_t;

ship_t *new_ship(int x, int y);
void draw_ship(ship_t *s);
bullet_t *shoot(ship_t *s);

#endif
