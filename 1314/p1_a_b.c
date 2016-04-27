int i, j;
int k, b;
int ks, bs;

/*@
  @    requires
  @      k == ks && b == bs;
  @
  @    requires
  @      j >= i;
  @
  @    ensures
  @      k == ks;
  @
  @    ensures
  @      b == bs;
  @
  @*/
void composition() {
  /*@
    @    loop assigns 
    @      k, b;
    @
    @    loop invariant
    @      i <= k <= (j + 1);
    @
    @    loop invariant
    @      b == \at(b, Pre) + (k - i);
    @  
    @    loop variant
    @      j - k;
    @
    @*/
  for(k = i; k <= j; k++) 
    b++;

  /*@
    @    loop assigns
    @      ks, bs;
    @
    @    loop invariant
    @      (i - 1) <= ks <= j;
    @
    @    loop invariant
    @      bs == \at(bs, Pre) + (j - ks);
    @
    @    loop variant
    @      ks - i;
    @
    @*/
  for(ks = j; ks >= i; ks--)
    bs++;
  ks = j + 1;
}

/*
 * A. 
 * $ frama-c -wp p1_a_b.c
 *
 * De notar que só conseguimos provar isto porque adicionamos a pré condção:
 *      j >= i
 *
 * B.
 * Se corrermos: 
 *
 * $ frama-c -wp -wp-rte p1_a_b.c
 *
 * Vemos que há VCs que não são validadas.
 * Adicionando pré-condições que limitam a gama de valores das variáveis
 * (e.g. 0 < variável < 1000) as VCs verificam-se.
 * 
 *
 */

