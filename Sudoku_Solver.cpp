class Solution {
public:
    int row[9][9], col[9][9], small_matrix[9][9];
    bool findSolution = false;

    void solveSudoku(vector<vector<char> > &board) {
        /* Initialize the row[][], col[][] and small_matrix[][] */
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int sx = (i / 3);
                    int sy = (j / 3);
                    row[i][num] = col[j][num] = small_matrix[sx*3+sy][num] = 1;
                }
            }
        }

        solveSudokuRecursion(board, 0, 0);
    }

    void solveSudokuRecursion(vector<vector<char> > &board, int row_num, int col_num) {
        if (row_num > 8) {
            findSolution = true;
            return;
        }

        if (board[row_num][col_num] != '.') {
            if (col_num < 8)
                solveSudokuRecursion(board, row_num, col_num+1);
            else
                solveSudokuRecursion(board, row_num+1, 0);
        } else {
            for (int n = 0; n < 9; ++n) {
                int sx = (row_num / 3);
                int sy = (col_num / 3);
                if ((row[row_num][n] || col[col_num][n] || small_matrix[sx*3+sy][n]) == 0) {
                    board[row_num][col_num] = '1' + n;
                    row[row_num][n] = col[col_num][n] = small_matrix[sx*3+sy][n] = 1;
                    if (col_num < 8)
                        solveSudokuRecursion(board, row_num, col_num+1);
                    else
                        solveSudokuRecursion(board, row_num+1, 0);
                    
                    if (findSolution)
                        return;
                    row[row_num][n] = col[col_num][n] = small_matrix[sx*3+sy][n] = 0;
                    board[row_num][col_num] = '.';
                }
            }
        }
    }
};
