int i, j;
int k, b;
int _k, _b;

/*@
  @    requires
  @      k == _k && b == _b;
  @
  @    ensures
  @      k == _k && b == _b;
  @
  @*/
void composition() {

  /*@
    @    loop assigns 
    @      k, b;
    @
    @    loop invariant
    @      i <= k <= (j + 1) &&
    @      b == \at(b, Pre) + (k - i);
    @  
    @    loop variant
    @      j - k;
    @*/
  for(k = i; k <= j; k++) 
    b++;

  /*@
    @    loop assigns
    @      _k, _b;
    @
    @    loop invariant
    @      (i - 1) <= _k <= j && 
    @      _b == \at(_b, Pre) + (j - _k);
    @
    @    loop variant
    @      _k - i;
    @*/
  for(_k = j; _k >= i; _k--)
    _b++;
  _k = j + 1;
}

/*
 * A. 
 * $ frama-c -main composition -wp p1_a.c
 *
 * B.
 * Se corrermos: 
 *
 * $ frama-c -main composition -wp -wp-rte p1_a.c
 * 
 * são geradas as VCs relativas aos overflow e são provadas.
 * O que é que temos que fazer aqui? 
 * Esta pergunta só fazia sentido para o Jessie?
 *
 */

