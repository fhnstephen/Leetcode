#include "algorithm"
#include "iostream"

using namespace std;
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (!k || !n) return;
        k = k % n;
        while (k--) {
          //swap step 1
          int temp = nums[n - 1];
          for (int i = 1; i < n; ++i)
            nums[i] = nums[i - 1];
          nums[0] = temp;
        }
    }
};

int main() {
  Solution s;
  int a[5] = {2147483647,-2147483648,33,219,0};
  s.rotate(a, 5, 4);
  for (int x : a)
    cout << x << " ";
}
