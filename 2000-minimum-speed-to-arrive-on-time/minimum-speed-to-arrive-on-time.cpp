class Solution {
public:
    bool check(vector<int> dist,double hour,int speed){
        int n=dist.size();
        double hrs=0;
        for(int i=0;i<n-1;i++){
            hrs+=(dist[i]+speed-1)/speed;
            if(hrs > hour) return false;
        }
        hrs+= (double)dist[n-1]/speed;
        return (hrs<=hour);

    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int low=1;
        int high=10000000;
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(dist,hour,mid)) high=mid;
            else low=mid+1;
        }
        return (check(dist,hour,low)) ? low : -1;
    }
};