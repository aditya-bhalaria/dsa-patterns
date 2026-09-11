class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int column=matrix[0].size();

        int start=0,end=row*column-1;
        while(start<=end){
            int mid=start+((end-start) >> 1);
            if(matrix[mid/column][mid%column]==target){
                return true;
            }
            else if(matrix[mid/column][mid%column]<=target){
                start=mid+1;
            }
            else{
              end=mid-1;
            }
        }
        return false;

    }
};