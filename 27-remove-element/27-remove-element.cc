class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int l = 0, r = 0;
        while (r < n) {
            while (r < n && A[r] == elem) ++r;
            if (r < n)
                A[l++] = A[r++];
        }
        return l;
    }
};
