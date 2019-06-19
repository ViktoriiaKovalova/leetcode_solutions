// first approach
/*
Runtime: 4 ms, faster than 99.71% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 9.3 MB, less than 82.91% of C++ online submissions for Longest Substring Without Repeating Characters.
*/
#include <vector>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <bool> used(256, false);
        int cur_len = 0;
        int max_len;
        int pos = 0;
        while (pos < static_cast<int>(s.size()) && !used[s[pos]]) {
            used[s[pos]] = true;
            ++cur_len;
            ++pos;
        }
        max_len = cur_len;
        int start = 1;
        while (start < static_cast<int>(s.size())) {
            --cur_len;
            used[s[start - 1]] = false;
            int end = start + cur_len;
            while ((end < static_cast<int>(s.size())) && !used[s[end]]) {
                used[s[end]] = true;
                ++end;
                ++cur_len;
            }
            if (cur_len > max_len) {
                max_len = cur_len;
            }
            ++start;
        }
        return max_len;
    }
};

// second approach
/*Runtime: 8 ms, faster than 97.59% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 10.7 MB, less than 69.54% of C++ online submissions for Longest Substring Without Repeating Characters.
*/
#include <vector>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> last_used(256, -1);
        int cur_len = 0;
        int max_len = 0;
        for (int pos = 0;pos < static_cast<int>(s.size());++pos) {
            if (last_used[s[pos]] < (pos - cur_len)) {
                ++cur_len;
                if (max_len < cur_len) {
                    ++max_len;
                }
            } else {
                cur_len = pos - last_used[s[pos]];
            }
            last_used[s[pos]] = pos;
        }
        return max_len;
    }
};
