class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int col=matrix[0].size();
        int s=0;
        int e=r*col-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            int el=matrix[mid/col][mid%col];
            if(el==target){
                return 1;
            }
            if(el<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;

        }
        return 0;
    }
};