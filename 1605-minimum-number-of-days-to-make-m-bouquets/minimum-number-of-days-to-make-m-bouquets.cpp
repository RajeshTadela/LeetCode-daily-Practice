class Solution {
public:
    bool bloom(vector<int> bloomDay,int m,int k,int days){
        int n=bloomDay.size();
        vector<int> bd(n,0);
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=days) bd[i]=1;
        }
        int m1=0;
        int k1=0;
        for(int i=0;i<n;i++){
            if(bd[i]==1) k1++;
            else k1=0;
            if(k1==k){
                m1++;
                k1=0;
            }
        }
        return (m1 >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k > n) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<high){
            int mid=low+(high-low)/2;
            if(bloom(bloomDay,m,k,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};