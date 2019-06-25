/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.


Runtime: 36 ms, faster than 81.64% of Python3 online submissions for Valid Parentheses.
Memory Usage: 13.3 MB, less than 28.92% of Python3 online submissions for Valid Parentheses.
*/

class Solution:
    def isValid(self, s: str) -> bool:
        close_to_open = {'}':'{', ')':'(', ']':'['}
        brackets = []
        for bracket in s:
            if self.isOpen(bracket):
                brackets.append(bracket)
            else:
                if len(brackets) == 0 or brackets.pop() != \
                                close_to_open[bracket]:
                    return False
        return len(brackets) == 0
    def isOpen(self, char: str) -> bool:
        return char == '(' or char == '[' or char == '{'
