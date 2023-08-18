class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        set<pair<int,int>> set;
        for(auto it:roads){
            degree[it[0]]++;
            degree[it[1]]++;
            set.insert({it[0],it[1]});
            set.insert({it[1],it[0]});
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=degree[i]+degree[j];
                if(set.find({i,j})!=set.end()) curr--;
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};