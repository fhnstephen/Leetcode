class Solution {
public:
    int removeDuplicates(int a[], int n) {
        int l = 0, r = 0;
        if (!n) return 0;
        while (r < n) {
            while (r < n && a[l] == a[r]) ++r;
            if (r < n) {
                a[++l] = a[r];
            }
        }
        return l + 1;
    }
};
