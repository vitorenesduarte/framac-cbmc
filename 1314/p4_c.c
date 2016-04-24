#include <assert.h>

int k, i, x, _x;
extern int MAX;

extern int u[MAX];
extern int _u[MAX];
extern int nondet_int();

int main() {
  x = _x = 1;

  for(i = 0; i < MAX; i++) {
    u[i] = nondet_int();
    _u[i] = nondet_int();
  }

  for(i = 0; i < MAX; i++)
    __CPROVER_assume(u[i] == _u[i]);

  // C1
  for(i = 0; i < MAX; i++)
    u[i] = u[i] * 2 + x;

  // C2
  for(i = 0; i < MAX; i++)
    _u[i] *= 2;
  // C3
  for(i = 0; i < MAX; i++)
    _u[i] += _x;


  for(k = 0; k < MAX; k++)
    assert(u[k] == _u[k]);

  return 1;
}

/*
 * C.
 * $ cbmc -unwind 100 p4_b.c | grep VERIFICATION
 *
 */
