/*
Given an array nums of n integers where n > 1,
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity?
(The output array does not count as extra space for the purpose of space complexity analysis.)

Runtime: 44 ms, faster than 56.63% of C++ online submissions for Product of Array Except Self.
Memory Usage: 12.5 MB, less than 62.66% of C++ online submissions for Product of Array Except Self.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        int len = nums.size();
        int cur = 1;
        for (int i = 0;i < len - 1;++i) {
            cur *= nums[i];
            output[i + 1] *= cur;
        }
        cur = 1;
        for (int i = len - 1;i > 0;--i) {
            cur *= nums[i];
            output[i - 1] *= cur;
        }
        return output;
    }
};
