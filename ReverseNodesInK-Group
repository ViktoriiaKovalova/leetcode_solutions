/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5



Runtime: 16 ms, faster than 98.52% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 9.7 MB, less than 74.63% of C++ online submissions for Reverse Nodes in k-Group.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode* prev = dummyhead;
        while (prev->next) {
            int cur_number = 1;
            ListNode* cur = prev->next;
            ListNode* first_in_group = cur;
            while (cur->next && cur_number < k) {
                cur = cur->next;
                ++cur_number;
            }
            if (cur_number < k) {
                break;
            } 
            reverseOneGroup(first_in_group, cur);
            prev->next = cur;
            prev = first_in_group;
        }
        return dummyhead->next;
    }
    void reverseOneGroup(ListNode* begin, ListNode* end) {
        ListNode* cur = begin;
        ListNode* next = begin->next;
        begin->next = end->next;
        while (cur != end) {
            ListNode* next_next = next->next;
            next->next = cur;
            cur = next;
            next = next_next;
        }
    }
};
