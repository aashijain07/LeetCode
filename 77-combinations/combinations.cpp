class Solution {
public:
    vector<vector<int>> ans;
    void helper(int i, int n, int k, vector<int>& v) {
        if (k == 0) {
            ans.push_back(v);
            return;
        }
        if (i > n) 
            return;
        v.push_back(i);
        helper(i + 1, n, k - 1, v);
        v.pop_back();
        helper(i + 1, n, k, v);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        helper(1, n, k, v);
        return ans;
    }
};