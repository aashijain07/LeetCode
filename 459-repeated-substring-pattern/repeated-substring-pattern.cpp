class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
       int n = s.length();
    
    if (n < 2) {
        return false;
    }
    
    for (int l = 1; l <= n/2; ++l) {
        if (n % l== 0) {
            string sub_str = s.substr(0, l);
            string reconstructed_str = "";
            for (int j = 0; j < n/l; ++j) {
                reconstructed_str += sub_str;
            }
            if (reconstructed_str == s) {
                return true;
            }
        }
    }
    
    return false;

        
    }
};


/*
class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        for(int i=s.size()-1; i>=0; i--){
            if(i==0) return false;
            string sub = s.substr(0,i);
            if(s+sub == sub + s) return true;
        }
        return false;
    }
};
*/