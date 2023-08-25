class Solution {
public:
    int dp[101][101][201] ;
    bool cal(int i ,int j , int k , string s1 ,string s2 , string s3 )
    {
 
        if(k==s3.length())
            return true ; 
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k] ; 
        
        bool ans =false; 
        
    if(s1[i]==s3[k] && s2[j]==s3[k])
    {
        ans = cal(i+1 ,j , k+1, s1 ,s2 ,s3 ) | cal(i ,j+1 , k+1 ,s1, s2 ,s3 );
    }
        
      if( i<s1.length() &&  s1[i]==s3[k])
      {
          ans|= cal(i+1, j ,k+1 , s1, s2 ,s3 ) ;
      }
        
        if(j<s2.length() && s2[j]==s3[k])
        {
            ans|=cal(i , j+1, k+1, s1 , s2, s3 ) ;
        }
        
        return dp[i][j][k] = ans ; 
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.length()+s2.length()!=s3.length())
            return false ;
        memset(dp ,-1 ,sizeof(dp)) ;
        return cal(0 ,0 , 0 , s1, s2 ,s3 ) ;
    }
};