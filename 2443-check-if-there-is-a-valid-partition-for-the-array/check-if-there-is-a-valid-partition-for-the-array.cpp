class Solution {
public:
int dp[100001];
    bool f(int i,vector<int> &nums){
        if(i>=nums.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(i+2<nums.size()){
            if(nums[i]==nums[i+1] && nums[i]==nums[i+2])
{
                return dp[i]=(f(i+3,nums) || f(i+2,nums));
}
else if(nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2]){
    return dp[i]=f(i+3,nums);
}
        }
        if(i+1<nums.size())
        {
            if(nums[i]==nums[i+1]){
                return dp[i]=f(i+2,nums);
            }
        }
        return dp[i]=false;

    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(0,nums);
    }
};