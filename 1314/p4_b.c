#include <assert.h>
#define MAX 100

int k, i, x, _x;

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
 * B.
 * $ time -p cbmc p4_b.c | grep VERIFICATION
 *
 * Para fazer a verificação falhar basta num dos ciclos C1, C2 ou C3
 * mudar a condição do ciclo para i < MAX - 1
 *
 *  --------------------------
 * | MAX   | slevel | time(s) |
 *  --------------------------
 * | 100   | 101    | 9.86    |
 * | 200   | 201    | 68.89   |
 * | 400   | 401    | 427.36  |
 *  --------------------------
 *
 */
