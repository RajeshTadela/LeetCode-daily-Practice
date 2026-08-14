class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        st=[]
        for ch in num:
            digit=int(ch)
            while(st and k > 0 and int(st[-1])>digit):
                st.pop()
                k-=1
            st.append(ch)
        while(k>0):
            st.pop()
            k-=1
        res="".join(st)
        res=res.lstrip('0')
        return res or "0"