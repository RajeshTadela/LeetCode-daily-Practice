class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack=[]
        score=0
        stack.append(0)
        for ch in s:
            if ch=='(':
                stack.append(0)
            else:
                val=stack.pop()
                score=max(2*val,1)
                stack.append(score+stack.pop())
            

        return stack[-1]