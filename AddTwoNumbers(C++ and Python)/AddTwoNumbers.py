/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/*
Runtime: 76 ms, faster than 85.42% of Python3 online submissions for Add Two Numbers.
Memory Usage: 13.1 MB, less than 85.25% of Python3 online submissions for Add Two Numbers.
*/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def calcVal(self, l: ListNode) -> int:
        if l:
            return l.val
        return 0
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummyhead = ListNode(0)
        cur = dummyhead
        carry = False
        while l1 or l2 or carry:
          sum = self.calcVal(l1) + self.calcVal(l2) + carry
          next = sum % 10
          carry = sum // 10
          cur.next = ListNode(next)
          cur = cur.next
          if l1:
            l1 = l1.next
          if l2:
            l2 = l2.next
        return dummyhead.next
