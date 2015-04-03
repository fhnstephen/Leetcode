class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((n + m) & 1) return findKth(A, m, B, n, (n+m) / 2 + 1);
        else             return (findKth(A, m, B, n, (n+m) / 2) + findKth(A, m, B, n, (n+m)/2 + 1)) /2.0;
    }
private:
    double findKth(int A[], int m, int B[], int n, int k) {
        if (m > n) return findKth(B, n, A, m, k);
        if (!m) return B[k - 1];
        if (!n) return A[k - 1];
        if (k == 1) return min(A[0], B[0]);

        int x = min(m, k/2);
        int y = k - x;
        int a = A[x - 1];
        int b = B[y - 1];
        if (a > b)
            return findKth(A, x, B + y, n - y, k - y);
        else if (b > a)
            return findKth(A + x, m - x, B, y, k - x);
        else
            return a;
    }
};
