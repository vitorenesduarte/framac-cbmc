#define N 15

extern int nondet_int();

int sum(int V[], int n) {
  int i, s = 0;

  for(i = 0; i < n; i++) {
    s = s + V[i];
  }

  return s;
}

void main() {
  int i;
  int arr[N];
  
  for(i = 0; i < N; i++) {
    arr[i] = nondet_int();
  }
  
  int y = nondet_int();
  __CPROVER_assume(0 <= y && y < N);
  
  int s = sum(arr, y);
}

/*
 * D.
 *
 * $ cbmc --bounds-check --pointer-check -function main p5_d.c
 *
 * Algo inesperado aconteceu. O cbmc não conseguiu para de fazer unwinding.
 * Porque é que isto acontece?
 *
 * Então para provar a correção do programa podemos tentar:
 *
 * $ cbmc --bounds-check --pointer-check -function main -unwind 10 p5_d.c
 * 
 * Verificação com sucesso. Mas na verdade só provamos que não há acessos inválidos nas primeiras 10 iterações do ciclo.
 * Se corrermos o comando seguinte vamos ver que o cbmc falha ao tentar provar a unwinding assertion.
 *
 * $ cbmc --bounds-check --pointer-check -function main -unwind 10 --unwinding-assertions p5_d.c
 *
 *
 * Precisamos então de passar ao cbmc um número suficiente grande para fazer a prova completa do programa:
 *
 * $ cbmc --bounds-check --pointer-check -function main -unwind 16 --unwinding-assertions p5_d.c
 *
 */
