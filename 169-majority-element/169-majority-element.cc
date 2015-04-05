class Solution {
public:
    // O(n) in time, O(n) in space
    int majorityElement_hash(vector<int> &num) {
        unordered_map<int, int> hash;
        int half = num.size() / 2, ansk = 0;
        for (auto& x : num) {
            hash[x]++;
            if (hash[x] > half) {
                ansk = x;
                break;
            }
        }
        return ansk;
    }

    // O(n) in time, O(1) in space
    int majorityElement_delete(vector<int> &num) {
        auto left = num.begin(), right = left + 1;
        while (right != num.end()) {
          while (right != num.end() && *right == *left) ++right;
          if (right != num.end()) {
              int x = *left;
              ++left;
              while (*left != x && left != right) ++left;
              if (left == right) ++left;
              ++right;
          }
        }
        return *left;
    }

    // O(n) in time, O(1) in space
    // But can not guarantee appears more than n/2
    // Only the number appears most times in `num`
    int majorityElement(vector<int> &num) {
        int cnt = 0, res = 0;
        for (auto& x : num) {
            if (!cnt) res = x;
            if (res == x) ++cnt;
            else          --cnt;
        }
        return res;
    }
};
