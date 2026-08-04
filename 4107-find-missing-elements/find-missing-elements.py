class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        n=len(nums);
        maxi=max(nums)
        mini=min(nums)
        missing_list=[]
        for i in range(mini,maxi+1):
            if i not in nums:
                missing_list.append(i)
        return missing_list