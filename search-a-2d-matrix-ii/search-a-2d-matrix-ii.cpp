class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int rowIndex=0;
        int colIndex=c-1;
        while(rowIndex<r && colIndex>=0){
            int el=matrix[rowIndex][colIndex];
            if(el==target){
                return 1;
            }
            if(el<target){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return 0;

    }
};