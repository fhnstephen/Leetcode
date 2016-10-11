class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        n = len(matrix)
        row = 0
        col = len(matrix[0]) - 1 if n > 0 else -1
        while row < n and col >= 0:
            x = matrix[row][col]
            if x == target:
                return True
            elif x < target:
                row = row + 1
            else:
                col = col - 1
        return False
       