class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int p=1;
        int i=n;
        while(i>0){
            int r=i%10;
            sum+=r;
            p*=r;
            i=i/10;
        }
        int d=sum+p;
        return n%d==0 ? true : false;
    }
};