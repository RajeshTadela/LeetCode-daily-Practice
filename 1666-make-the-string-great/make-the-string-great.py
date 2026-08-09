class Solution:
    def makeGood(self, s: str) -> str:
        stack=[]
        for ch in s:
            if stack and stack[-1].lower()==ch.lower():
                if stack[-1].isupper() and ch.isupper():
                    stack.append(ch)
                    continue
                elif stack[-1].isupper() or ch.isupper():
                    stack.pop()
                    continue
            stack.append(ch)
        return "".join(stack)