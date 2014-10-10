class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if(row == 0)  return;
        int col = matrix[0].size();
        if(col == 0)  return;
        
        bool first_row_zero = false, first_col_zero = false;
        
        /* Scan the first row */
        for(int i = 0; i < col; i++) {
            if(matrix[0][i] == 0) {
                first_row_zero = true;
                break;
            }
        }
            
        /* Scan the first column */
        for(int i = 0; i < row; i++) {
            if(matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }
        }

            
        if(row == 1) {
            if(first_row_zero)
                for(int i = 0; i < col; i++)
                    matrix[0][i] = 0;
            return;
        }
        if(col == 1) {
            if(first_col_zero)
                for(int i = 0; i < row; i++)
                    matrix[i][0] = 0;
            return;
        }
        
        /* We can use the first row and the first column as count-boards. */
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }    
            }
        }
        
        for(int i = 1; i < row; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < col; j++)
                    matrix[i][j] = 0;
            }
        }
        for(int i = 1; i < col; i++) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < row; j++)
                    matrix[j][i] = 0;
            }
        }
        
        if(first_row_zero)
            for(int i = 0; i < col; i++)
                matrix[0][i] = 0;
        if(first_col_zero)
            for(int i = 0; i < row; i++)
                matrix[i][0] = 0;
                
    }
};
