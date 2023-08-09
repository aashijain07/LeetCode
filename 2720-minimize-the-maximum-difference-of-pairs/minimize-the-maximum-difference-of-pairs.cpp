class Solution {
public:
    bool isPossible(int diff,vector<int>&nums,int p){
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] - nums[i-1] <= diff){
                p--;
                i++;
            }
        }
        return p <= 0;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int l = 0, r = nums[n-1] - nums[0];
        int result = r;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isPossible(mid,nums,p)){
                result = mid;
                r = mid-1;
            }else{
                l = mid + 1;
            }
        }
        return result;
    }
};