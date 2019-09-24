#ifndef BULLET_H_
#define BULLET_H_

typedef struct {
  int x;
  int y;
} bullet_t;

bullet_t *new_bullet(int x, int y);
void draw_bullet(bullet_t *b);
void update_bullet(bullet_t *b);

#endif
