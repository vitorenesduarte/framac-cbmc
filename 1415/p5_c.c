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
  int i, y;
  int arr[N];
  
  for(i = 0; i < N; i++) {
    arr[i] = nondet_int();
  }

  y = 12;

  int s = sum(arr, y);
}

/*
 * C.
 *
 * $ cbmc --signed-overflow-check -function main p5_c.c
 *
 * Como de esperado conseguimos ver o cbmc a gerar valores no array para os quais é possível ter overflow.
 *
 */
