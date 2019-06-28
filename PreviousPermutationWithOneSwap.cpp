/*
Given an array A of positive integers (not necessarily distinct), 
return the lexicographically largest permutation that is smaller than A,
that can be made with one swap (A swap exchanges the positions of two numbers A[i] and A[j]).
If it cannot be done, then return the same array.


Runtime: 108 ms, faster than 89.42% of C++ online submissions for Previous Permutation With One Swap.
Memory Usage: 12.7 MB, less than 100.00% of C++ online submissions for Previous Permutation With One Swap.
*/

#include <algorithm>
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        if (A.size() > 1) {
            int i = static_cast<int>(A.size()) - 2;
            while (i >= 0 && A[i] <= A[i + 1]) {
                --i;
            }
            if (i != -1) {
                auto it = lower_bound(A.begin() + i + 1, A.end(), A[i]);
                --it;
                it = lower_bound(A.begin() + i + 1, A.end(), *it);
                swap(A[i], *it);
            }
        }
        return A;
    }
};
