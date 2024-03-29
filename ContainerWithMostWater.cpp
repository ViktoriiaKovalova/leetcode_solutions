/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
*/

Note: You may not slant the container and n is at least 2.
/*
First solution !!!!SLOW!!!!
O(nlogn)
*/
/*
Runtime: 44 ms, faster than 23.78% of C++ online submissions for Container With Most Water.
Memory Usage: 12.5 MB, less than 5.27% of C++ online submissions for Container With Most Water.
*/

#include <map>
#include <algorithm>
using std::map;
class Solution {
public:
    int maxArea(vector<int>& height) {
        long long max_possible = 0;
        max_possible = std::max(findMax(height.begin(), height.end()), 
                               findMax(height.rbegin(), height.rend()));
        return max_possible;
    }
    template <class ForwardIterator>
    int findMax(ForwardIterator begin, ForwardIterator end) {
        map <int, int> positions;
        long long max_possible = 0;
        int i = 0;
        while (begin != end) {
            auto possible_pair = positions.lower_bound(*begin);
            if (possible_pair != positions.end()) {
                long long new_max = static_cast<long long>(*begin) * 
                    (i - possible_pair->second);
                if (new_max > max_possible) {
                    max_possible = new_max;
                }
            } else {
                positions[*begin] = i;
            }
            ++i;
            ++begin;
        }
        return max_possible;
    }
};

/*
O(n) solution

Runtime: 12 ms, faster than 98.74% of C++ online submissions for Container With Most Water.
Memory Usage: 9.7 MB, less than 66.59% of C++ online submissions for Container With Most Water.
*/

#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& height) {
        long long max_possible = 0;
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        while (right - left) {
            long long cur_max = std::min(height[left], height[right]) *
                (right - left);
            if (max_possible < cur_max) {
                max_possible = cur_max;
            }
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_possible;
    }
};
