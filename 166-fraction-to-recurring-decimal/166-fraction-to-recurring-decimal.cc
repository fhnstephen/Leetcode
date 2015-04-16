class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;
        unordered_map<long, long> m;
        int s1 = numerator < 0, s2 = denominator < 0;
        int s = s1 ^ s2;
        if (s && numerator != 0) ans += '-';
        ans += to_string(abs(long(numerator)/long(denominator)));
        long n = abs(long(numerator));
        long d = abs(long(denominator));
        long remainder = n%d;
        if (remainder)
          ans += ".";
        while (remainder) {
            auto& pos = m[remainder];
            if (pos) {
                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            pos = ans.length();
            remainder *= 10;
            ans += to_string(remainder / d);
            remainder = remainder % d;
        }
        return ans;
    }
};
