class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, ans = INT_MAX, sum = 0;
        int n = nums.size();

        while( right < n){
            sum += nums[right];

            while(sum >= target && left <= right){
                ans = ans < right - left +1 ? ans : right - left +1;
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};