class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int row = matrix.size();
        if (row <= 0)
            return res;
        int col = matrix[0].size();
        if (col <= 0)
            return res;
        
        /* Direction: right, down, left, up */
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int cur_x = 0, cur_y = -1, cur_direction = 0;
        int hor_step = col, vertical_step = row - 1;
        int remain_hor_step = hor_step, remain_vertical_step = vertical_step;
        int ct = 0, size = row * col;
        while (++ct <= size) {
            cur_x += dx[cur_direction];
            cur_y += dy[cur_direction];
            res.push_back(matrix[cur_x][cur_y]);
            if (cur_direction == 0 || cur_direction == 2) {
                if (--remain_hor_step == 0) {
                    cur_direction = (cur_direction + 1) % 4;
                    remain_hor_step = (--hor_step);
                }
            } else if (cur_direction == 1 || cur_direction == 3) {
                if (--remain_vertical_step == 0) {
                    cur_direction = (cur_direction + 1) % 4;
                    remain_vertical_step = (--vertical_step);
                }
            }
        }
        return res;
    }
};
