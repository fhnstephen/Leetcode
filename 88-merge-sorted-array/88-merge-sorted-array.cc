class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        while (n > 0)
          A[n+m-1] = m == 0 || A[m-1] < B[n-1] ? B[--n] : A[--m];
    }
};
