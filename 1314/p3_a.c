#define MAX 100

int k, verif, i, x, _x;

extern int u[MAX];
extern int _u[MAX];

int main() {
  verif = 1;
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
    verif = verif && (u[k] == _u[k]);

  return 1;
}

/*
 * A.
 * MAX = 100
 * $ time -p frama-c -val -slevel 100 p3_a.c | grep verif
 *
 * Se no output virmos:
 *    verif ∈ {0}
 *    verif ∈ {0; 1}
 *    
 * é porque o slevel definido não é suficiente para verificar.
 * Para termos a certeza que foi verificado temos que ter o seguinte output:
 *    verif ∈ {0}
 *    verif ∈ {1}
 *
 *  --------------------------
 * | MAX   | slevel | time(s) |
 *  --------------------------
 * | 100   | 101    | 0.80    |
 * | 200   | 201    | 1.60    |
 * | 400   | 401    | 3.70    |
 * | 800   | 801    | 9.38    |
 * | 1600  | 1601   | 30.22   |
 * | 3200  | 3201   | 518.99  |
 *  --------------------------
 *
 */
