class Solution {
public:
    int mySqrt(int x) {
        if (x==0 || x==1) return x;
        int left=1;
        int right=x/2;
        while(left <= right){
            long long mid=left+ (right-left)/2;
            long long s=mid*mid;
            if (s==x) return mid;
            else if(s<x) left=mid+1;
            else right=mid-1;
        }
        return right;
    }
};