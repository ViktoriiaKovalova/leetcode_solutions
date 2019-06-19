/*
Runtime: 16 ms, faster than 95.23% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 9.7 MB, less than 69.89% of C++ online submissions for Median of Two Sorted Arrays.
*/

#include <limits>
#include <algorithm>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int left = 0, right = nums1.size();
        int half_elements = (nums1.size() + nums2.size()) / 2;
        while (left < right) {
            int middle = (left + right) / 2;
            int second_middle = half_elements - middle;
            if (El(nums1, middle) >= El(nums2, second_middle - 1)) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        if ((nums1.size() + nums2.size()) & 1) {
            int second_middle = half_elements - left;
            return std::min(El(nums1, left), El(nums2, second_middle));
        } else {
            int second_middle = half_elements - left;
            int first_m = std::max(El(nums1, left - 1), El(nums2, second_middle - 1));
            int second_m = std::min(El(nums1, left), El(nums2, second_middle));
            return (first_m + second_m) / 2.0;
        }
    }
    int El(vector<int>& nums1, int pos) {
        if (pos < 0) {
            return std::numeric_limits<int>::min();
        }
        if (pos >= static_cast<int>(nums1.size())) {
            return std::numeric_limits<int>::max();
        }
        return nums1[pos];
    }
};
