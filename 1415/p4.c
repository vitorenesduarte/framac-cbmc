#define N 100

extern int nondet_int();

int vec[N];

int min(int A[], int size) {
  int i = 1;
  int m = 0;

  while(i < size) {
    if(A[i] < A[m]) { m = i; }

    i++;
  }

  return m;
}

void main() {
  int i;

  for(i = 0; i < N; i++) {
    vec[i] = i;
  }

  int r = min(vec, N);
}

/*
 * A.
 *
 * $ cbmc p4.c --function min --bounds-check --pointer-check
 *
 * A execução não para porque o cbmc está a tentar fazer 
 * unwinding do ciclo presente na função para uma sequência de 
 * ifs aninhados sem saber o valor do size, ou seja, 
 * não consegue decidir quando parar o unwinding.
 *
 *
 * B. 
 * 1.
 *
 * $ cbmc p4.c --function min --unwind 100 --bounds-check --pointer-check
 *
 * Aqui é normal a verificação falhar porque não estamos a assumir nada 
 * sobre o array e o size passados à função (como faziamos no frama-c).
 * Para um array qq é normal que haja acessos out of bounds 
 * (em que o size seja maior do que o tamanho do array).
 * O cbmc ainda dá um exemplo mais simples: 
 * - o apontador para o array aponta para NULL.
 *
 *
 * C.
 *
 * $ cbmc p4.c --bounds-check --pointer-check
 *
 * O programa main está correto em termos de acesso ao array.
 * 
 */
