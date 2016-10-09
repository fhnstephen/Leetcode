class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        ans = 0
        i = 0
        j = len(height) - 1
        while i < j:
            if height[i] < height[j]:
                ans = max(ans, (j - i) * height[i])
                i = i + 1
            elif height[j] < height[i]:
                ans = max(ans, (j - i) * height[j])
                j = j - 1
            else:
                ans = max(ans, (j - i) * height[j])
                i = i + 1;
                j = j - 1;
        return ans