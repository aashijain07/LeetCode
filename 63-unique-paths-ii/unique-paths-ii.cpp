class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n=Grid.size();
            int m=Grid[0].size();
        vector<vector<long long int>>dp(n,vector<long long int>(m));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(Grid[i][j]==1)
                    dp[i][j]=0;
                else if(i==n-1 and j==m-1)
                    dp[i][j]=1;
                else if(i==n-1){
                    dp[i][j]=dp[i][j+1];
                }
                else if(j==m-1){
                    dp[i][j]=dp[i+1][j];
                }
                else{
                    dp[i][j]=dp[i][j+1]+dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};