class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, pair<int, int>> m;
        for (int i = 0; i < numbers.size(); ++i) {
            int index = i + 1;
            if (m.count(numbers[i])) {
              m[numbers[i]].second = index;
            }
            else
              m[numbers[i]].first = index;
        }
        for (int i = 0; i < numbers.size(); ++i) {
            int index = i + 1;
            int x = numbers[i];
            if (m.count(target - x)) {
              if (m[target - x].first == index) {
                if (m[target - x].second)
                  return {index, m[target - x].second};
                else
                  continue;
              }
              return {index, m[target - x].first};
            }
        }
    }
};
