#include "util.h"

/*@
  @   requires
  @     valid_array(arr, size);
  @         
  @   ensures
  @     \result == 0 <==> not_belongs(y, arr, size);
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
 * D.
 * $ frama-c -wp p1_d.c 
 *
 */
