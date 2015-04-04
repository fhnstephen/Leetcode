#[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

> There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

##思路

1. 最朴素的做法上将两个数组合并起来，然后排序求中位数，时间复杂度如果使用快速排序为`O(NlogN)`，其中`N=n+m`。

2. 使用归并排序中的`merge`算法将两个有序的数组直接合并起来，然后求中位数，时间复杂度为`O(N)`。

3. 题目要求的时间复杂度为`O(logN)`，给了算法的提示。要想达到log的时间复杂度，分治的思想基本上是少不了的。  
   考虑类似于二分查找的算法。问题的本质是要找出两个有序数组中的第k小的数字。显然，我们可以用`O(1)`的时间找出某个数组中的第k小。
   假设现在我们有数组A中第`a`小的数`xa`，数组B中第`b`小的数`xb`，其中`a+b=k`。那么存在以下三种可能：
   1. `xa == xb`。 这种情况下，`xa`和`xb`均是这两个数组中的第k小数。因为这两个数在这两个数组中均**大于等于(k-1)个数**。
   2. `xa > xb`。 这种情况下，`xa`**至少大于(k-1)个数**，而`xb`**最多大于(k-2)个数**。因为第k小的数必须满足**大于等于(k-1)个数**的条件，所以小于等于`xb`的数都不可能是第k小的数了。那么我们可以将小于等于`xb`的数从数组中剔除，在剩下的数中查找第(k-b)小的数。
   3. `xa < xb`。这种情况和2类似，小于等于`xa`的数都不可能是我们所要找的数了。

   每次取数的时候采用二分法，可以每次取到k/2。这样的递归算法，时间复杂度为O(logk)，找中位数就是O(log(n + m))，达到了题目的要求。

##实现

实现的时候主要是会容易存在shift-by-one的问题。这种时候思路必须要清晰，概念和模型必须要明确。

写代码之前应该先想清楚这些问题，再开始写，比如`在c++数组里，第k小的数是a[k-1]`，`小于等于第k小的数一共有k个`等。
