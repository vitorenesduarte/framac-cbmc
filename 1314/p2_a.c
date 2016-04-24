int i, j;
int k, b, a;
int _k, _b, _a;

/*@
  @    requires
  @      k == _k && a == _a && b == _b;
  @
  @    ensures
  @      k == _k && a == _a && b == _b;
  @
  @*/
void composition() {

  /*@
    @   loop assigns
    @     k, b;
    @
    @   loop invariant
    @     i <= k <= (j + 1) &&
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
    @     i <= k <= (j + 1) &&
    @     a == \at(a, Here) * 2;
    @   
    @   loop variant
    @     j - k;
    @
    @*/
  for(k = i; k <= j; k++)
    a *= 2;


  /*@
    @   loop assigns
    @     _k, _b, _a;
    @
    @   loop invariant
    @     i <= _k <= (j + 1) &&
    @     _b == \at(_b, Pre) + (_k - i) &&
    @     _a == \at(_a, Here) * 2;
    @
    @   loop variant
    @     j - _k;
    @
    @*/
  for(_k = i; _k <= j; _k++) {
    _b++;
    _a *= 2;
  }
}

/*
 * (Ver p1_a.c)
 *
 * Não percebo porque é que "_a == \at(_a, Here) * 2" funciona.
 * Qual a diferença entre Pre, Old, Here, etc?
 * Onde podem ser usados?
 *
 */
