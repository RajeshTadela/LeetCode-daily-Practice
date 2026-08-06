class Solution {
public:
    int smallestNumber(int n, int t) {
        if(t==1) return n;
        int p;
        int ans;
        int q;
        for(int i=n;i>0;i++){
            q=i/10;
            if (q==0) {p=q+i;}
            else{p=q*(i%10);}
            if(p%t==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};