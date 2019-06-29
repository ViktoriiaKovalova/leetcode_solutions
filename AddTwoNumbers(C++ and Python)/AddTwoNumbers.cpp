/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order
and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/*
Runtime: 24 ms, faster than 84.78% of C++ online submissions for Add Two Numbers.
Memory Usage: 10.4 MB, less than 54.28% of C++ online submissions for Add Two Numbers.
*/

/*
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
*/
    
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool plus = false;
        int sum;
        ListNode *beforetop = new ListNode(0);        
        ListNode *result = beforetop;
        while(l1 || l2 || plus) {
            int sum = calcVal(l1) + calcVal(l2) + plus;
            result->next = new ListNode(sum % 10);
            plus = sum / 10;
            result = result->next;
            
            if(l1) {
                l1 = l1->next;
            }
            if(l2) {
                l2 = l2->next;
            }
        }
        return beforetop->next;
    }
    int calcVal(ListNode * lp) {
        if(lp) {
            return lp->val;
        }
        return 0;
    }
};
