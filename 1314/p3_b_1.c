#define MAX 1

int k, verif, i, x, _x;

extern int u[MAX];
extern int _u[MAX];
extern int value;

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
 * 1)
 * MAX = 1
 * $ time -p frama-c -val -slevel 1000000000 p3_b_1.c 
 *
 * Declarando o valor presente em todas as posições do array
 * como extern faz com que o plugin de análise de valor não 
 * consiga determinar o valor de verif (0 ou 1)
 * mesmo que o array só tenha uma posição.
 * E não importa o quão grande é o valor do slevel.
 *
 * Justificação?
 * - o frama-c não vai atribuir um valor concreto à variável "value", 
 *   mas sim um intervalo. 
 *   No fim ao calcular o valor do verif vai comparar dois intervalos,
 *   o que dá falso (a não ser que o intervalo seja tão pequeno
 *   que só tem um valor)
 *   
 */
