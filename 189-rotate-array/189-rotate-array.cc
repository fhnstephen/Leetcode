class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if (n < 2 || k % n == 0) return;
        k = k % n;
        int temp_index = 0;
        int temp = nums[0];
        int i = 0;
        for (int j = 0; j < n; ++j) {
            int after = (i - k + n) % n;
            if (after == temp_index) {
                nums[i] = temp;
                i++;
                temp_index = i;
                temp = nums[i];
            }
            else {
                nums[i] = nums[after];
                i = after;
            }
        }
    }
};
