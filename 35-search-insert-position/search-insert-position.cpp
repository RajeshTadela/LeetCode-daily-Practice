class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int left=0;
        int right=n;
        while(left<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            else if(target < nums[mid]) right=mid;
            else left=mid+1;
        }
        return left;
    }
};