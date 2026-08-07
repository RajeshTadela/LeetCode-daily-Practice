class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n=asteroids.size();
        s.push(asteroids[0]);
        for(int i=1;i<n;i++){
            int num=asteroids[i];
            bool alive=true;
            while(!s.empty() && s.top()>0 && num<0){
                if(s.top() < abs(num)){
                    s.pop();
                }
                else if(s.top()==abs(num)){
                    s.pop();
                    alive=false;
                    break;
                }
                else{
                    alive=false;
                    break;
                }
            }
            if(alive) s.push(num);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};