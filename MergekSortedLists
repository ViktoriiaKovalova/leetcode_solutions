/**
Runtime: 28 ms, faster than 80.56% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 11.7 MB, less than 33.97% of C++ online submissions for Merge k Sorted Lists.



 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include <queue>
#include <vector>
using std::priority_queue;

struct CompList { 
bool operator () (ListNode * lhs, ListNode * rhs)const {
        return lhs->val > rhs->val;
}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <ListNode *,std::vector <ListNode *>, CompList> mins;
        for (ListNode* pointer:lists) {
            if (pointer) {
                mins.push(pointer);
            }
        }
        ListNode* dummyhead = new ListNode(0);
        ListNode* cur = dummyhead;
        while (!mins.empty()) {
            ListNode* min = mins.top();
            cur->next = new ListNode(min->val);
            cur = cur->next;
            ListNode* next = min->next;
            mins.pop();
            if (next) {
                mins.push(next);
            }
        }
        return dummyhead->next;
    }
};
