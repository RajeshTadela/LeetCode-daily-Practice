class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> rows;
        for(auto &seat:reservedSeats){
            rows[seat[0]].push_back(seat[1]);
        }
        int m=(n-rows.size())*2;
        for(auto &p:rows){
            vector<int>& reserved=p.second;
            bool left=true;
            bool middle=true;
            bool right=true;
            for(int seat: reserved){
                if(seat>=2 && seat<=5) left=false;
            }
            for(int seat: reserved){
                if(seat>=4 && seat<=7) middle=false;
            }
            for(int seat: reserved){
                if(seat>=6 && seat<=9) right=false;
            }
            if(left && right) m+=2;
            else if (left || middle || right) m+=1;
        }
        return m;
        
           
    }
};