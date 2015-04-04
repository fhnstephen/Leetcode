class Solution {
public:
    int reverse(int x) {
        long long result = solve(x);
        if (result > numeric_limits<int>::max()) return 0;
        else return result;
    }
private:
    int solve(int x, int acc = 0) {
        if (!x) return acc;
        else  {
          int next = acc*10;
          if (next / 10 != acc) return 0;
          next = acc*10 + x%10;
          if ((next - x%10)/10 != acc) return 0;
          return solve(x/10, next);
        }
    }
};
