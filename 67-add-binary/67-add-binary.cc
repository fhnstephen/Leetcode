class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        int l1 = a.size(), l2 = b.size();
        for (int i = 1; i <= l2; ++i)
            a[l1 - i] += b[l2 - i] - '0';
        for (int i = 1; i < l1; ++i)
            if (a[l1 - i] > '1') {
                a[l1 - i - 1]++;
                a[l1 - i] -= 2;
            }
        if (a[0] > '1') {
            a[0] -= 2;
            a = "1" + a;
        }
        return a;
    }
};
