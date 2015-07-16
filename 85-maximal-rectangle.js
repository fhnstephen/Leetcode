/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    if (!matrix.length) return 0;
    var n = matrix.length, m = matrix[0].length, row = new Array(m), i, j, k, l, ans = 0, tmp;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j)
            row[j] = 1;
        for (j = i; j < n; ++j) {
            for (k = 0; k < m; ++k)
                row[k] = row[k] && (matrix[j][k] == "1");
            tmp = 0;
            for (k = 0; k < m; ++k) {
                if (row[k]) ++tmp;
                else tmp = 0;
                var tmpAns = tmp * (j - i + 1);
                if (tmpAns > ans) ans = tmpAns;
            }
        }
    }
    return ans;
};
