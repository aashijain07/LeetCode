class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int a=nums1.size();
        int n=nums2.size();
        for(int i=0; i<n; i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        int m=nums1.size();
        double ans1=0;
        double ans=0;
        if(m%2!=0)
        {
            int mid=m/2;
            ans=nums1[mid];
            return ans;
        }
        else
        {   
            int mid=m/2;
            int mid1=(m/2)-1;
            ans1=double(nums1[mid]+nums1[mid1])/2;
        }
        return ans1;
    }
};