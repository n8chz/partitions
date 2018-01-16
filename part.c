/*
  Partition function p(n) is the number of distinct ways of expressing n as a
  sum of some number of natural numbers.

  This program outputs a table of values of p(n)
  for the first few natural numbers.

  We define an intermediate function p(k, n) which is defined as the number
  of partitions of n in which all addends are >= k.

*/
#include <stdio.h>

#define SIZE 306
#define HALFSIZE SIZE/2+6

long long p[HALFSIZE][SIZE];

int main(int argc, char **argv) {
 int k, n;
 for (n = 1; n<SIZE; n++) {
  for (k = HALFSIZE; k >= 1; k--) {
   if (k > n) {
    /* There's no way to partition a number into numbers larger than itself: */
    p[k][n] = 0;
   }
   else if (2*k > n) {
    /*
       If an addend is more than half as large as the target, the second
       largest addend has to be less than half. Such a sum contains an
       addend < k and therefore is not among the p(k, n) partitions containing
       only addends >= k
    */
    p[k][n] = 1;
   }
   else {
    /*
       All partitions into addends >= k fall into one of two categories:

       1. Partitions having at least one addend which is >= k+1
       2. Partitions whose smallest addend is k.

       Each of the partitions in the second category is k plus some partition
       of n-k into numbers at least as big as k.
    */
    p[k][n] = p[k+1][n]+p[k][n-k];
   }
   if (k == 1) {
    printf("p(%d) = %lld\n", n, p[1][n]);
   }
  }
 }
}



