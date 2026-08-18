class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n){
            return *max_element(nums.begin(),nums.end());
        }
        if(k==1){
            unordered_map<int,int> f;
            for(int p:nums){
                f[p]++;
            }
            int ans=-1;
            for(auto &p:f){
                if(p.second==1){
                    ans=max(ans,p.first);
                }
            }
            return ans;
        }
        int l=0;
        int r=k-1;
        unordered_map<int,int> freq;
        while(r<n){
            for(int i=l;i<=r;i++){
                freq[nums[i]]++;
            }
            l++;
            r++;
        }
        int m=-1;
        if(freq[nums[0]]==1) m=max(m,nums[0]);
        if(freq[nums[n-1]]==1) m=max(m,nums[n-1]);
        return m;
    }
};