Karatsuba Multiplication
========================

Fast way to multiply long integers.
In regular grade school multiplaction, the number of multiplacation is 
proportional to **O(n^2)** where _n_ is the length of integer.

We can reduce this using divide and conquer paradigm. The algorithm to do so 
was found by guy named [Karatsuba](http://en.wikipedia.org/wiki/Karatsuba_algorithm).

Let's assume we want to multiply two integers, **X** and **Y**.
We can split these numbers into equal parts,
* X = 10^(n/2)\*A + B
* Y = 10^(n/2)\*C + D
* X\*Y = 10^n\*A\*C + 10^(n/2)\*(A\*D + C\*B) + B\*D, where
* (A\*D + C\*B) = (A+B)\*(C+D) - A\*C - B\*D

Therefore we can get the product of X and Y by recursively calculating 
all other terms and sum/subtract them accordingly.

Notice that, multiplacation by 10^n means shifting the number to left.

![results](results.pdf)

I use Unix bc calculator to check the correctness of my implementation.
(Apparently it uses simple multiplacation method)

Usage
-----
./run\_tests.sh

TODO
----
* <s>Use vectors</s>
* <s>Check sign</s>
