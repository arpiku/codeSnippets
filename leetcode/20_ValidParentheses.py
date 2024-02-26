
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        memo = {'}':'{', ')':'(', ']':'['}
        for ch in s:
            if(len(stack) == 0 and ch in memo):
                return False
            if(len(stack) != 0 and ch in memo):
                if(stack.pop() != memo[ch]):
                    return False
            else:
                stack.append(ch)
        return len(stack) == 0

