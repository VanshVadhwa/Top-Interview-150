class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            vector<bool> rows(9,false);
            vector<bool> cols(9,false);
            for(int j=0;j<9;j++) {
                // row check
                char c1 = board[i][j];
                if(c1 != '.') {
                    if(rows[c1-'1']) return false;
                    rows[c1-'1'] = true;
                }
                // col check
                char c2 = board[j][i];
                if(c2!='.') {
                    if(cols[c2-'1']) return false;
                    cols[c2-'1'] = true;
                }
            }
        }
        
        // square check
        for(int i=0;i<9;i+=3) {
            for(int j=0;j<9;j+=3) {
                vector<bool> square(9,false);
                for(int r=i;r<i+3;r++) {
                    for(int c=j;c<j+3;c++) {
                        if(board[r][c]=='.') continue;
                        if(square[board[r][c]-'1']) return false;
                        square[board[r][c]-'1'] = true;
                    }
                }
            }
        }

        return true;
    }
};
