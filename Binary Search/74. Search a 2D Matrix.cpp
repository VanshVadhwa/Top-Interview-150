class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0, end = row*col-1;

        while(start <= end) {
            int mid = start + (end-start)/2;
            int rowIndex = mid/col;
            int colIndex = mid%col;
            int value = matrix[rowIndex][colIndex];

            if(value==target) return true;
            else if(value < target) start = mid+1;
            else end = mid-1;
        }

        return false;
    }
};
