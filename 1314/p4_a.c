#include <assert.h>
#define MAX 100

int k, i, x, _x;

extern int u[MAX];
extern int _u[MAX];

int main() {
  x = _x = 1;

  for(k = 0; k < MAX; k++)
    u[k] = _u[k] = k;

  for(i = 0; i < MAX; i++)
    u[i] = u[i] * 2 + x;

  for(i = 0; i < MAX; i++)
    _u[i] *= 2;
  for(i = 0; i < MAX; i++)
    _u[i] += _x;


  for(k = 0; k < MAX; k++)
    assert(u[k] == _u[k]);

  return 1;
}

/*
 * A.
 * $ time -p cbmc p4_a.c | grep VERIFICATION
 *
 *  --------------------------
 * | MAX   | slevel | time(s) |
 *  --------------------------
 * | 100   | 101    | 0.25    |
 * | 200   | 201    | 0.65    |
 * | 400   | 401    | 1.30    |
 * | 800   | 801    | 4.22    |
 * | 1600  | 1601   | 17.27   |
 * | 3200  | 3201   | 146.39  |
 *  --------------------------
 *
 */
