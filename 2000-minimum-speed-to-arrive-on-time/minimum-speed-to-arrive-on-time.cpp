class Solution {
public:
     bool pred(int speed, vector<int>&dist,double hour){
          double time=0;
          for(int i=0;i<dist.size();i++){
              int d=dist[i];
              
              if((d%speed)==0)time+=d/speed;
              else{
                  if(i==dist.size()-1){
                      time+= (double)d/ double(speed);
                  }else{
                  time+= d/speed;
                  time+=1;
                  }
              }
          }
          return time<=hour;
     }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=1e7;
        int ans=-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(pred(mid,dist,hour)){
                ans=mid;
                high=mid-1;

            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};