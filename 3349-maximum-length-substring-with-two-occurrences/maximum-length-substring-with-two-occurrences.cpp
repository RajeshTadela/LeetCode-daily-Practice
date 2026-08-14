class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int left=0;
        int m=0;
        unordered_map<char,int> freq;
        for(int right=0;right<n;right++){
            freq[s[right]]++;
            while(freq[s[right]]>2){
                freq[s[left]]--;
                left++;
            }
            m=max(m,right-left+1);
        }

        return m;
    }
};