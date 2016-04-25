#include "util.h"

/*@
  @   requires
  @     valid_array(arr, size);
  @         
  @   ensures
  @     \result == 0 
  @       <==> 
  @     \forall integer k; 
  @       0 <= k < size ==> arr[k] != y;
  @
  @   assigns
  @     \nothing;
  @
  @*/
int belongs(int y, int arr[], int size) {
  int i = 0;

  /*@
    @   loop assigns
    @     i;
    @
    @   loop invariant
    @     0 <= i <= size &&
    @     \forall integer k;
    @       0 <= k < i ==> arr[k] != y;
    @   
    @*/
  while(i < size) {
    if(arr[i] == y) return 1;

    i = i + 1;
  }

  return 0;
}
/*
 * B.
 * C. 
 *
 * Não percebo a diferença entre a B e a C.
 *
 * $ frama-c -wp p1_b_c.c 
 *
 * A diferença talvez seja:
 * - para safety basta um invariante com: 0 <= i <= size
 *
 */
