Best Time to Buy and Sell Stock IV
====

Say you have an array for which the ith element is the price of a given stock on day i.


Design an algorithm to find the maximum profit. You may complete at most k transactions.


Note:


You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

想法：

第一想法是动态规划。

状态:

1. dp[i][k][0]: 第i天已经做了k次transaction且手上没有股票时总共获得的利润。
2. dp[i][k][1]: 同上，区别是此时手上有股票，可以卖股票。

状态转移:

1. dp[i][k][0] = max{dp[i-1][k][0], dp[i-1][k-1][1] + prices[i]}
2. dp[i][k][1] = max{dp[i-1][k][1], dp[i-1][k][0] - prices[i]}

状态总数：2NK, 转移时间复杂度:O(1)，总时间复杂度为O(NK)。

一般来说这个算法还是不错的了，但是数据规模N可以达到10^4,而k更是可以达到10^9。

反观这个动态规划算法，其实非常朴素，几乎就是在枚举。

优化：

1. k如果大于等于n/2，那么k这个参数就失去了意义，变成了可以买卖任意次股票，那么状态可以去掉k这一维度，变成2N，总时间复杂度变成O(N)。但是这个优化在k比较大又小于n/2时没有用。

2. 预处理数据。profits数组里的单调增序列和单调减序列是无意义的，只需要保留峰值即可，很容易证明买卖购票只可能在峰值上进行。

3. 优化（2）在极端情况下也是没有效果的。顺延2的思路，考虑做进一步的“无用值处理”。实际想一想会发现一些特殊情况：

  a b c d ... e ... (a < b, b > c, c < d)

  * case 1： a > c

    如果a > c，那么就不可能出现买a之后再卖e了，因为肯定不如买c再卖e。如果不止买一个？那也会是买a卖b买c卖e。简而言之，由于在a之后紧接着有一个c比它小，所以如果买a的话，若不是马上在b处卖掉，只会导致没有机会买c，这样不管在哪里卖，显然不如买c再卖利润高。结论是如果买a，在这种情况下只有在b处卖才能使最优的。所以，这种时候，我们可以把b-a作为一个利润值profit保存起来，扔到一个数组里。由此推演出贪心算法。从一个保存了所有最佳profit的数组里取最大的k个。但是只有这个case，不足以保证贪心的正确性，因为还有case2：

  * case 2 ： a <= c, d > b

    这种情况下，显然如果要在这四个中做一次交易，最佳的是a买d卖。但是如果要做两次交易，还是应该abcd的顺序买卖。所以我们不能简单地把bc忽略掉。

    如果做一次，那就是d - a。如果做两次，就是 b - a + d - c。结论是，如果我们把b和c从列表中删去，必须记录一个值，那就是 b - c.这样做了之后，选择一个是d - a，选择两个是d - a + b - c = b - a + d - c，使得可能的选择没有被抹去。

    所以，这里需要做的是将b - c的值加入到profit里，然后留下a d，继续做case1和case 2的向前扫描清除工作。

由2和3这两个想法的综合，可以得到一个不一样的解法，那就是利用一个栈来保存<min, max>对，在合适的时候将<min, max>对出栈，然后加入到一个数组里，最后从数组里取k个最大值（且均应该大于0）累加得到答案。

整个算法只需要扫描一次prices数组，取k个最大值可以用排序或者堆来完成，时间复杂度是O(N + NlogN)。

当k满足条件1的时候，还可以用O(N)的算法来解决。

至此，这个问题完美解决了。
