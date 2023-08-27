class Solution {
public:

    bool helper(int prevJump,int ind, vector<int>& stones, unordered_map<int,int>&mp,int n,vector<vector<int>>&dp){

        // If ind reach at last index this means frog jump to the last stones 
        if(ind==n-1) return true;
        if(dp[prevJump][ind]!=-1) return dp[prevJump][ind];
        bool x = false;
        bool y = false;
        bool z = false;
       
       // check if previous jump + 1 + stones[ind] is presend in the stones array or not if presend then jump
        if(mp.find(prevJump+1+stones[ind])!=mp.end()){
            y =  helper(prevJump+1,mp[prevJump+1+stones[ind]],stones,mp,n,dp);
        }

         // check if previous jump  + stones[ind] is presend in the stones array or not if presend then jump
        if(mp.find(prevJump+stones[ind])!=mp.end()){
            x = helper(prevJump,mp[prevJump+stones[ind]],stones,mp,n,dp);
        }

         // check if previous jump - 1 + stones[ind] is presend in the stones array or not if presend then jump
        if(prevJump-1>0 and mp.find(prevJump-1+stones[ind])!=mp.end()){
            z = helper(prevJump-1,mp[prevJump-1+stones[ind]],stones,mp,n,dp);
        }
        
        
        return dp[prevJump][ind] =  x or y or z;
    }

    bool canCross(vector<int>& stones) {
        
        if(stones[1]>1) return false;
        unordered_map<int,int>mp;
        int n = stones.size();
        
        // store the all value with index in map
        for(int i = 0;i<n;i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>>dp(2001,vector<int>(2001,-1));
        return helper(1,1,stones,mp,n,dp);
    }
};