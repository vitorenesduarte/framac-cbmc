#ifndef UTIL_H__INCLUDED
#define UTIL_H__INCLUDED

/*@
  @   predicate
  @     not_belongs(integer y, int* arr, integer size) =
  @       \forall integer k;
  @         0 <= k < size ==> arr[k] != y;
  @
  @   predicate
  @     belongs(integer y, int* arr, integer size) =
  @       !not_belongs(y, arr, size);
  @
  @   predicate
  @     valid_array(int* arr, integer size) = 
  @       size >= 0 &&
  @       \valid(arr + (0..(size - 1)));
  @
  @*/

#endif
