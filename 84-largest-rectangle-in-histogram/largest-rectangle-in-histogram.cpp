class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int max_area=0;
        stack<int> s;
        for(int i=0;i<=n;i++){
            int h=(i==n) ?0: heights[i];
            while(!s.empty() && h < heights[s.top()]){
                int height=s.top();
                s.pop();
                int width = (!s.empty())? i-s.top()-1 : i;
                int area=heights[height]*width;
                max_area=max(area,max_area);
            }
            s.push(i);
        }
        return max_area;
    }
};