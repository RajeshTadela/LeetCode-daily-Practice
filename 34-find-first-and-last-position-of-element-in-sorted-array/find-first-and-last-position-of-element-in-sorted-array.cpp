class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1,-1};
        }
        int n=nums.size();
        int l1=0;
        int r1=n;
        while(l1<r1){
            int mid=l1+(r1-l1)/2;
            if(nums[mid] >= target) r1=mid;
            else l1=mid+1;
        }
        int first=l1;
        if(first==n || nums[first]!=target){
            return {-1,-1};
        }
        int l2=0;
        int r2=n;
        while(l2<r2){
            int mid=l2+(r2-l2)/2;
            if(nums[mid] > target) r2=mid;
            else l2=mid+1;
        }
        int last=l2-1;
        return {first,last};
    }
};