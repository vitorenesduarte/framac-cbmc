/*@
  @   axiomatic Exponentation {
  @     logic integer exp(integer b, integer e);
  @
  @     axiom exp0:
  @       \forall integer b;
  @         exp(b, 0) == 1;
  @
  @     axiom exp1:
  @       \forall integer b;
  @         exp(b, 1) == b;
  @
  @     axiom expn:
  @       \forall integer b, integer e;
  @         exp(b, e) == b * exp(b, e - 1);
  @
  @   }
  @
  @*/


int i, j;
int k, b, a;
int ks, bs, as;

/*@
  @    requires
  @      k == ks && a == as && b == bs;
  @
  @    requires
  @      j >= i;
  @
  @    ensures
  @      k == ks;
  @
  @    ensures
  @      a == as;
  @    
  @    ensures
  @      b == bs;
  @
  @*/
void composition() {

  /*@
    @   loop assigns
    @     k, b;
    @
    @   loop invariant
    @     i <= k;
    @
    @   loop invariant
    @     k <= (j + 1);
    @
    @   loop invariant
    @     b == \at(b, Pre) + (k - i);
    @
    @   loop variant
    @     j - k;
    @
    @*/
  for(k = i; k <= j; k++)
    b++;
  /*@
    @   loop assigns
    @     k, a;
    @
    @   loop invariant
    @     i <= k;
    @
    @   loop invariant
    @     k <= (j + 1);
    @
    @   loop invariant
    @     a == \at(a, Pre) * exp(2, k - i);
    @   
    @   loop variant
    @     j - k;
    @
    @*/
  for(k = i; k <= j; k++)
    a *= 2;


  /*@
    @   loop assigns
    @     ks, bs, as;
    @
    @   loop invariant
    @     i <= ks;
    @
    @   loop invariant
    @     ks <= (j + 1);
    @
    @   loop invariant
    @     bs == \at(bs, Pre) + (ks - i);
    @
    @   loop invariant
    @     as == \at(as, Pre) * exp(2, (ks - i));
    @
    @   loop variant
    @     j - ks;
    @
    @*/
  for(ks = i; ks <= j; ks++) {
    bs++;
    as *= 2;
  }
}

/*
 * A.
 * 
 * $ frama-c -wp p2_a.c
 *
 * Mais uma vez precisamos da pré-condição
 *     j >= i
 */
