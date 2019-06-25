/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.


Runtime: 4 ms, faster than 99.09% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 9.8 MB, less than 55.67% of C++ online submissions for Longest Palindromic Substring.
*/
//O(n) solution using 

#include <algorithm>
class Solution {
public:
    string longestPalindrome(string s) {
        string new_string;
        for (char c:s) {
            new_string.push_back('#');
            new_string.push_back(c);
        }
        new_string.push_back('#');
        vector <int> lengths_of_palindroms(new_string.length(), 0);
        int cur_center = 0;
        int cur_right = 0;
        int cur_left = 0;
        for (int ind = 1;ind < static_cast<int>(lengths_of_palindroms.size());++ind) {
            if (cur_right < ind) {
                
                lengths_of_palindroms[ind] = Extend(1, new_string, ind);
                
            } else {
                int symmetric_pos = 2 * cur_center - ind;
                if (symmetric_pos - lengths_of_palindroms[symmetric_pos] > 
                   cur_left) {
                    
                    lengths_of_palindroms[ind] = lengths_of_palindroms[symmetric_pos];
                    
                } else if (symmetric_pos - lengths_of_palindroms[symmetric_pos] < 
                   cur_left) {
                    
                    lengths_of_palindroms[ind] = cur_right - ind; 
                    
                } else { // if equal

                    lengths_of_palindroms[ind] = Extend(lengths_of_palindroms[symmetric_pos] + 1,
                                                       new_string, ind);
                }
                
            }
            if (lengths_of_palindroms[ind] + ind > cur_right) {
                cur_center = ind;
                cur_left = ind - lengths_of_palindroms[ind];
                cur_right =  ind + lengths_of_palindroms[ind];
            }
        }
        auto greatest_pal = std::max_element(lengths_of_palindroms.begin(),
                                            lengths_of_palindroms.end());
        int index = greatest_pal - lengths_of_palindroms.begin();
        int from = index - lengths_of_palindroms[index];
        int to = index + lengths_of_palindroms[index];
        return string(s.begin() + from / 2, s.begin() + (to + 1) / 2);
    }
    int Extend(int initial_len, const string& str, int pos) {
        while ( (pos + initial_len < static_cast<int>(str.size())) &&
               (pos - initial_len >= 0) ){
            if (str[pos + initial_len] == str[pos - initial_len]) {
                ++initial_len;
            } else {
                break;
            }
        }
        return initial_len - 1;
    }
};
