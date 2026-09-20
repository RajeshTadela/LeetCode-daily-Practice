class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int degree=0;
        for(int i=0;i<n;i++){
            int p=int(s[i])-97;
            degree+= (i+1)*(26-p);
        }
        return degree;
    }
};