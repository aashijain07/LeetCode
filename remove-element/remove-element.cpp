class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        int n=nums.size();
        while(j<n)
        {   //cout<<i<<" "<<j<<endl;
            if( nums[i]==val && nums[j]!=val)
            {
                swap(nums[i],nums[j]);
                if(i<n)
                i++;
                if(j<n)
                j++;
            }
            while(i<n && nums[i]!=val)i++;
            while(j<n && nums[j]==val)j++;
            if(i>j)j=i;
        }
        return i;
    }
};