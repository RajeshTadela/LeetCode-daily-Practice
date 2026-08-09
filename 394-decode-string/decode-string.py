class Solution:
    def decodeString(self, s: str) -> str:
        stack=[] 
        for ch in s:
            if ch!=']':
                stack.append(ch)
            else:
                string=[]
                while stack[-1]!='[':
                    string.append(stack.pop())
                stack.pop()
                string.reverse()
                num=[]
                while stack and stack[-1].isdigit():
                    num.append(stack.pop())
                num.reverse()
                repeat=int("".join(num))
                
                repeated=[]
                for i in range(repeat):
                    repeated.extend(string)
                
                for c in repeated:
                    stack.append(c)
        result=[]
        while stack:
            result.append(stack.pop())
        result.reverse()
        return "".join(result)