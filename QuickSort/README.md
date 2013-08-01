QUICKSORT
=========

Another sorting algorithm.

It uses three different partitioning strategies,
* Select first element as a pivot
* Select median of first, middle and last elements as a pivot
* Select last element as a pivot
for the purpose of counting comparisons.

While strategy first and last results in relatively same amount of 
comparisons, median achieves at least 2x less comparisons.


Usage
-----

<code> g++ quicksort.cpp -DSTRATEGY && ./a.out N </code>
where,
* STRATEGY is FIRST, LAST or MEDIAN
* N is number of elements to sort (elements are created as random integers)
