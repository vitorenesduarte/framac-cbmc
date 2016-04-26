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
  __CPROVER_assert(0 <= r && r < N, "valid index");

  int k = nondet_int();
  __CPROVER_assume(0 <= k && k < N);
  __CPROVER_assert(vec[r] <= vec[k], "the min is the min");
}

/*
 * D.
 * E.
 *
 * $ cbmc p4_d_e.c --bounds-check --pointer-check
 * 
 */
