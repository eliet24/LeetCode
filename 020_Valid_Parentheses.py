class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        if len(s) % 2 != 0:
            return False

        for p in s:
            if p == '(' or p == '[' or p == '{':
                stack.append(p)
            elif p == ')' and len(stack) > 0:
                if stack[-1] == '(':
                    stack.pop()
                else:
                    return False
            elif p == ']' and len(stack) > 0:
                if stack[-1] == '[':
                    stack.pop()
                else:
                    return False
            elif p == '}' and len(stack) > 0:
                if stack[-1] == '{':
                    stack.pop()
                else:
                    return False
            else:
                return False

        return len(stack) == 0
