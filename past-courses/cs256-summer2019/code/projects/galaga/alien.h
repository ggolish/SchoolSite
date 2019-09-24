#ifndef ALIEN_H_
#define ALIEN_H_

#include "bullet.h"

#define MAX_ALIENS 100

typedef enum {
  LEFT,
  RIGHT,
  DOWN
} astate_t;

typedef struct {
  int x;
  int y;
} alien_t;

typedef struct {
  alien_t *aliens[MAX_ALIENS];
  int length;
  astate_t state;
} agroup_t;

alien_t *new_alien(int x, int y);
agroup_t *new_agroup();
void draw_alien(alien_t *s);
void draw_agroup(agroup_t *ag);
bullet_t *alien_shoot(alien_t *s);
void update_aliens(agroup_t *aliens);

#endif
