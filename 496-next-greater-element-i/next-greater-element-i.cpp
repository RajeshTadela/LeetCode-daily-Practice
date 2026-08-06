class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> index(n1);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    index[i]=j;
                    break;
                }
            }
        }
        stack<int> s;
        vector<int>a(n2,-1);
        for(int i=n2-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(!s.empty()){
                a[i]=s.top();
            }
            s.push(nums2[i]);
        }
        vector<int> ans(n1);
        for(int i=0;i<n1;i++){
            ans[i]=a[index[i]];
        }
        return ans;
    }
};