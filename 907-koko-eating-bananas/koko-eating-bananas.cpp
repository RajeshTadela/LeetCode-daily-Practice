class Solution {
public:

    bool check(vector<int> piles,int h,int k){
        int s=0;
        for(int pile:piles){
            s+=(pile+k-1)/k;
            if (s>h) return false;
        }
        return true;
        
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(piles,h,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};