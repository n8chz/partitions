
  Partition function p(n) is the number of distinct ways of expressing n as a
  sum of some number of natural numbers.
  This program outputs a table of values of p(n)
  for the first few natural numbers.
  
  We define an intermediate function p(k, n) which is defined as the number
  of partitions of n in which all addends are >= k.

  This function can be defined recursively:

                 / 0 (k > n)
      p(k, n) = {  1 (k = n)
                 \ p(k+1, n)+p(k, n-k) (k < n)
