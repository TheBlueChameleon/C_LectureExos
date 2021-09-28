#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ========================================================================= //

/* This is an advanced form of the binary representation task that works with
 * arbitrary data types (even ones I'm only going to show you later on). Also
 * I'm using some fancy tricks here that you might find interesting if you
 * go down the rabbit hole that programming in C can be at times.
 */

// ========================================================================= //

int getBit(char * data, int bitID) {
  /* We want to test the bit at position [bitID] of an arbitrary data object.
   * To that end, we'll pass the information where to find the object as a
   * char *.
   * Why that data type?
   * An arbitrary data object can have any length. A char is exactly one byte.
   * So, no matter how many bytes our data object takes, we can fit it into an
   * array of bytes with no extra space.
   *
   * Now, a byte has eight bit. The [bitID] is supposed to be relative to the
   * beginning of our data object.
   * Say, we have a 32bit object and want to check its 11th bit. There is no
   * 11th bit in a byte. We need to go to the second byte and check its third
   * bit instead.
   *
   * So, in general, we do:
   * byte = bitID / 8;
   * bit  = bitID % 8;
   */

  int byte = bitID >> 3;      // equivalent to division by 8
  int bit  = bitID  & 7;      // equivalent to modulo 8: 7_dec = 111_bin
                              // ==> we catch the bits that were shifted out of
                              // reach by the "division" bitID >> 3.

  /* Albeit equivalent here, the methods shown above are slightly more efficient
   * than their straight-forward counterparts. a / b is implemented in more
   * general terms. The circuits for the generic division are ignorant of the
   * fact that for powers of two, you can do a simple bitshift.
   *
   * Imagine the situation in decimal:
   * You know how a division in general works, and that it takes you some time
   * to figure out the result. However, if the divisor is 10, 100, 1000, ...,
   * you'll have no trouble at all finding the answer, no matter the dividend:
   * You simply move the decimal point by a number of places given by the number
   * of zeros (and forget about the fractional part of the result, as we're
   * interested in integers only).
   * That's because the divisor is a power of your base system (i.e. a power of
   * 10). Likewise, when dividing by a power of two, we can do that trick in
   * silico: we can replace the complicated instructions for the generic
   * division by a simple bitshift!
   *
   * Likewise, the remainder of a division is tricky to find in general, but if
   * we divide by a power of our number base (10 or 2, respectively), then the
   * remainder is simply what we cut off when doing our bit-shift. So we only
   * need to find a number where all the bits 0..(n-1) are set. That number is
   * (2^n) - 1
   */

  return (data[byte] & (1 << bit)) != 0;
  /* This translates to:
   * regard the relevant byte we've found before:
   *    data[byte]
   * Now, prepare a test number where exactly one bit in position [bit] is set:
   *    1 << bit
   * The bitwise AND (&) of these two numbers will be zeros in all places except
   * maybe where the shifted one ended up. In other words, if b = 2^k, then
   * a & b can have at most one bit set. Thus, it is either zero if the kth bit
   * of a was not set, or it is equal to 2^k.
   * Consequently,
   *    data[byte] & (1 << bit)
   * is either zero or nonzero, depending on the state of the [bit]th bit.
   * For convenience, we boil that down to a 0/1 answer, instead of a
   * 0/something_nonzero answer, by ending in
   *    ... != 0
   */
}

// ------------------------------------------------------------------------- //

void setBit(char * data, int bitID) {
  int byte = bitID >> 3;      // same tricks as in getBit
  int bit  = bitID  & 7;
  
  data[byte] = data[byte] | (1 << bit);
  /* If we do the bitwise OR (|) can only set a bit or leave it as it was if it
   * was set before. With this we can apply the ideas from before.
   */
}

// ------------------------------------------------------------------------- //

void resetBit (char * data, int bitID) {
  int byte = bitID >> 3;      // same tricks as in getBit
  int bit  = bitID  & 7;

  data[byte] &= !(1 << bit);
  /* We start by preparing a mask where only one bit in the correct spot is set:
   *    1 << bit
   * Now, we flip that mask, i.e. we put zeros where there used to be ones and
   * vice versa:
   *    !(1 << bit)
   * gives a pattern like 11111011 (if bit was 2).
   * With this now we can perform a bitwise AND and store the result in the
   * corresponding part of data:
   *    data[byte] &= ...
   *
   * Note that this line will give a warning. There are means of suppressing
   * them, but that goes well beyond the scope of our lecture. If you want to
   * get rid of the warning, use a helper variable:
   *    char mask = (1 << bit);
   *    data[byte] &= !mask;
   */
}

// ========================================================================= //

int main () {
  double num  = 4. * atan(1);                               // approximately pi.
  int    bits = sizeof(num) * 8;

  printf("printing the original number:\n");
  printf("%lf(dec) = ", num);
  for (int i = bits - 1; i >= 0; i--) {
    printf(
      "%d",
      getBit( (char*) &num, i )
    );
  }
  printf("(bin)\n");
  printf("\n");


  printf("flipping the sign bit:\n");
  setBit( (char*) &num, bits - 1 );

  printf("%lf(dec) = ", num);
  for (int i = bits - 1; i >= 0; i--) {
    printf(
      "%d",
      getBit( (char*) &num, i )
    );
  }
  printf("(bin)\n");
  printf("\n");
}
