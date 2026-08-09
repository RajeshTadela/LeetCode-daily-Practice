class Solution:
    def decodeString(self, s: str) -> str:
        digits=[];
        c=[];
        current=""
        num=0
        for ch in s:
            if ch.isdigit():
                num=num*10+ int(ch)

            elif ch=='[':
                digits.append(num)
                c.append(current)
                num=0
                current=""
            elif ch==']':
                count=digits.pop()
                previous=c.pop()
                current=previous+ current*count
            else:
                current=current+ch
                
        return current