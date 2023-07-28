class Solution {
public:
    bool f(vector<int>& nums,int i, int j, int p1, int p2, bool turn){
        if(i>j) return p1>=p2;
        if(turn)
            return f(nums,i+1,j,p1+nums[i],p2,false)|| f(nums,i,j-1,p1+nums[j],p2,false);
        
        return f(nums,i+1,j,p1,p2+nums[i],true)&& f(nums,i,j-1,p1,p2+nums[j],true) ;
        
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        return f(nums,0,nums.size()-1,0,0,true);
    }
};