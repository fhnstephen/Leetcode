class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return search(num, 0, num.size() - 1);
    }
private:
    int search(const vector<int> & a, int l, int r) {
        if (l >= r) return l;
        int x = (l + r) >> 1;
        int lval = x ? a[x - 1] : numeric_limits<int>::min();
        int rval = x + 1 < a.size() ? a[x + 1] : numeric_limits<int>::min();
        int k = a[x];
        if (lval < k && k > rval) return x;
        else if (lval <= k && k <= rval) return search(a, x + 1, r);
        else return search(a, l, x - 1);
    }
};
