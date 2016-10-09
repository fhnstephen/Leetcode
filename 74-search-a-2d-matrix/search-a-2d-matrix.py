class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        n = len(matrix)
        m = len(matrix[0]) if n > 0 else 0
        left = 0
        right = n - 1
        while left <= right:
            mid = left + ((right - left) >> 1)
            val = matrix[mid][0]
            if val == target:
                return True
            elif val > target:
                right = mid - 1
            else:
                left = mid + 1
        x = left - 1 if left == n or matrix[left][0] > target else left
        left = 0
        right = m - 1
        while left <= right:
            mid = left + ((right - left) >> 1)
            val = matrix[x][mid]
            if val == target:
                return True
            elif val > target:
                right = mid - 1
            else:
                left = mid + 1
        return False
        