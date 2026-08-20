class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> nums1;
        vector<int> nums2;
        nums1.push_back(nums[0]);
        nums2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            int n1=nums1.size();
            int n2=nums2.size();
            if(nums1[n1-1] > nums2[n2-1]) nums1.push_back(nums[i]);
            else nums2.push_back(nums[i]);
        }
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            result.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            result.push_back(nums2[i]);
        }
        return result;
    }
};