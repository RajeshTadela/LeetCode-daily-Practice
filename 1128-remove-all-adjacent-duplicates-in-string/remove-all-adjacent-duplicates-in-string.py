class Solution:
    def removeDuplicates(self, s: str) -> str:

        stack=[]
        for ch in s:
            if stack and stack[-1]==ch:
                p=stack.pop()
                continue
            stack.append(ch)
        return "".join(stack)
        