class Solution {

    vector<int> peopleMask;
    vector<vector<int>> dp;
    int n, m, maxMask;
    

    void PreProcess(vector<string>& req_skills, vector<vector<string>>& people)
    {
        n = req_skills.size();
        m = people.size();
        maxMask = (1 << n) - 1;
        unordered_map<string, int> strToInt;
        peopleMask.resize(m);
        dp = vector<vector<int>>(m, vector<int>(maxMask + 1, -1));;

        for(int i = 0; i < n; i++)
            strToInt[req_skills[i]] = i;

        for(int i = 0; i < m; i++)
        {
            int mask = 0;
            for(auto &skill : people[i])
                mask = mask | (1 << strToInt[skill]);
            peopleMask[i] = mask;
        }
    }


    int DFS(int index, int mask)
    {
        if(mask == maxMask)
            return 0;

        if(index >= m)
            return n + 1; 

        if(dp[index][mask] != -1)
            return dp[index][mask];

        int skip = DFS(index + 1, mask);
        
        int keep = 1 + DFS(index + 1, mask | peopleMask[index]);

        return dp[index][mask] = min(skip, keep);
    }
    
    vector<int> CreateArray()
    {
        vector<int> ans;
        int index = 0, mask = 0;
        
        while(index < m && mask != maxMask)
        {
            if(index + 1 >= m || 1 + dp[index + 1][mask | peopleMask[index]] < dp[index + 1][mask])
            {
                ans.push_back(index);
                mask = mask | peopleMask[index];
            }
            index++;
        }

        return ans;
    }

public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        
        PreProcess(req_skills, people);
        
        DFS(0, 0);
        
        return CreateArray();
    }
};