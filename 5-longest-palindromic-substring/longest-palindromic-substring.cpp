class Solution {
public:
    bool is_palindrome(string &s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int max_len = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(is_palindrome(s,i,j))
                {
                    int curr_len = j-i+1;
                    if(curr_len>max_len)
                    {
                        max_len = curr_len;
                        start = i; 
                       // if we get max len that prev then we will make start index = i 
                       //as longest palindrome will start from this index only
                    }
                }
            }
        }
        int starting_index = start;
        int ending_index = max_len;
        string ans = s.substr(starting_index,ending_index);
        return ans;
    }
};