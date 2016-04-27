#define MAX 1

int k, verif, i, x, _x;

extern int u[MAX];
extern int _u[MAX];
extern int value;

/*@
  @   requires 0 < value < 2
  @
  @*/
int main() {
  verif = 1;
  x = _x = 1;

  for(k = 0; k < MAX; k++)
    u[k] = _u[k] = value;

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
 * B.
 * 2)
 * Com a pré-condição só consegue verificar se esta definir um valor concreto para o value, e.g.:
 *         
 *          0 < value < 2
 *
 * Se alterarmos a pré-condição para:
 *        
 *          0 < value < 3
 *
 * já não vai conseguir determinar o valor de verif.
 *
 * Justificação?
 * - a justifição é a mesma dada no p3_b_1.c
 *
 */
