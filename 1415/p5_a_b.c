#define N 15

int sum(int V[], int n) {
  int i, s = 0;

  for(i = 0; i < n; i++) {
    s = s + V[i];
  }

  return s;
}

void main() {
  int i, y;
  int arr[N] = {33, 25, -43, 1, 5, 3, -2, 4, -5, 19, 0, 23, 11, 53, 1};

  y = 12;

  int s = sum(arr, y);
}

/*
 * A.
 *
 * $ cbmc --signed-overflow-check -function sum p5.c 
 *
 * O comando acima não é suficiente para tentar perceber se ha problemas de overflow pois o cbmc vai tentar fazer unwinding para sempre.
 *
 * $ cbmc --signed-overflow-check -unwind 10 -function sum p5.c 
 *
 * Aqui já conseguimos ver o cbmc a encontrar um exemplo que faz com que haja overflow
 *
 *
 * B. cbmc --signed-overflow-check --bounds-check --pointer-check -function main p5.c 
 * 
 * Todos os acessos ao array são validos uma vez que estamos a percorrer as primeiras 12 posições e o array tem um tamanho de 15.
 * O somatório das primeiras 12 posições do array definido também não provoca overflow.
 *
 *
 */
