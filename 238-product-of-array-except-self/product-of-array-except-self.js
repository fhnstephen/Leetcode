/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    var ans = [],
        i,
        len = nums.length,
        l = nums[0];
    for (i = 0; i < len; ++i) ans.push(1);
    for (i = 1; i < len; ++i) {
        ans[i] *= l;
        l *= nums[i];
    }
    l = nums[len - 1];
    for (i = len - 2; i >= 0; --i) {
        ans[i] *= l;
        l *= nums[i];
    }
    return ans;
};
