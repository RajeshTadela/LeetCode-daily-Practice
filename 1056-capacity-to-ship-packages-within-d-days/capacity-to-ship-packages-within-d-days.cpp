class Solution {
public:
    bool check(vector<int> weights,int days,int k){
        int n=weights.size();
        int i;
        int s=0;
        for(i=0;i<n;i++){
            if(days==0) break;
            if(s+weights[i]<=k){
                s+=weights[i];
                if(s==k){
                    s=0;
                    days--;
                }
            }
            else{
                days--;
                if(days==0) return false;
                s=weights[i];
            }
        }
        return (i==n)?true: false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int weight:weights){
            high+=weight;
        }
        while(low < high){
            int mid=low+(high - low)/2;

            if(check(weights,days,mid)){
                high=mid;
            }
            else low=mid+1;
        }
        return low;
    }
};