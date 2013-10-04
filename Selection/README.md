SELECTION (Order Statistics)
============================

Given an array of elements (integers), find the <code>Kth</code> smallest element.


Solution:Sorting
----------------

Intiutive and simple solution would be, first sort (using comparison based sorting) the elements and then return the <code>Kth</code> element. This will result in <code>O(NlogN)</code> performance. But, can we do better? As a matter of fact we can.

Solution:Randomized Selection
-----------------------------

In Quicksort after partitioning we end up with two halves of elements, those smaller than pivot and those larger. Depending on the <code>K</code> we can eliminate the one of the branches. As a result this gives us, on average, <code>O(N)</code> performance. It is average case analysis due to fact that we are selecting pivot element randomly. Analysis of this algorithm is very interesting.

Solution:Deterministic Selection
--------------------------------

Median of medians.
