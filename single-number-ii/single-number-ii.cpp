class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums)m[i]++;
        int ans=0;
        for(auto j:m){
          if(j.second==1){
              ans= j.first;
              break;
          }
        }
        return ans;
        
    }
};