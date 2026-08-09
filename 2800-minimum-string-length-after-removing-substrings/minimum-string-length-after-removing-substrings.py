class Solution:
    def minLength(self, s: str) -> int:
        stack=[]
        s1=''
        for ch in s:
            
            if stack:
                s1=stack[-1]
                s1=s1+ch
            if s1=='AB' or s1=='CD':
                stack.pop()
                s1=''
                continue
            
            stack.append(ch)
            
        return len("".join(stack))