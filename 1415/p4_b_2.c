#define N 100

extern int nondet_int();

int vec[N];

int min(int A[], int size) {
  __CPROVER_assume(*A != 0);
  int k = nondet_int();
  __CPROVER_assume(0 <= k && k < size);
  __CPROVER_assume(*(A + k) != 0);

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
 *
 * B. 
 * 2.
 *
 * $ cbmc p4.c --function min --unwind 100 --bounds-check --pointer-check
 *
 * Aqui poderíamos provar a correção da função min se assumíssemos um array válido à entrada (como no frama-c).
 * O código acima tenta fazer isso.
 * O contra-exemplo do cbmc já é outro, mas não é claro qual é o problema agora.
 * Como solucionar isto?
 *
 */
