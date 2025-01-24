class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans(row*col,0);
        int index = 0;

        int top = 0, right = col-1, bottom = row-1, left = 0;

        while(left<=right && top <= bottom) {
            for(int i=left;i<=right;i++) {
                ans[index++] = matrix[top][i];
            }
            top++;

            for(int i=top;i<=bottom;i++) {
                ans[index++] = matrix[i][right];
            }
            right--;

            if(top <= bottom)
            for(int i=right;i>=left;i--) {
                ans[index++] = matrix[bottom][i];
            }
            bottom--;

            if(left <= right)
            for(int i=bottom;i>=top;i--) {
                ans[index++] = matrix[i][left];
            }
            left++;
        }

        return ans;
    }
};
