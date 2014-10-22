class Solution {
public:
    vector<vector<bool> > vis;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    bool existRecursion(vector<vector<char> > &board, string &word, int prev_x, int prev_y, int pos) {
        if (pos == word.size())
            return true;
        
        for (int dir = 0; dir < 4; ++dir) {
            int next_x = prev_x + dx[dir];
            int next_y = prev_y + dy[dir];
            if (next_x >= 0 && next_x < board.size() && next_y >= 0 && next_y < board[0].size()) {
                if (board[next_x][next_y] == word[pos] && !vis[next_x][next_y]) {
                    vis[next_x][next_y] = 1;
                    if (existRecursion(board, word, next_x, next_y, pos+1))
                        return true;
                    vis[next_x][next_y] = 0;
                }
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0)
            return true;
        size_t row = board.size();
        if (row == 0)
            return false;
        size_t col = board[0].size();
        if (col == 0)
            return false;
        
        vis.resize(row);
        for (int i = 0; i < row; ++i)
            vis[i].resize(col);
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if (existRecursion(board, word, i, j, 1))
                        return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};
