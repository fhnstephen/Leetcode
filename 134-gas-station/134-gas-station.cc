class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        n = gas.size();
        if (n <= 0) return 0;
        int start = 0, end = 0, cur = 0;
        while (start < n && end != start + n) {
            int c = cost[end % n];
            cur += gas[end % n];
            if (cur >= c) {
                cur -= c;
                end = end + 1;
            }
            else {
                start = end + 1;
                end = start;
                cur = 0;
            }
        }
        if (start >= n) return -1;
        else            return start;
    }
private:
    int n;
    inline int f(int x) {
        return x >= n ? x - n : x;
    }
};
