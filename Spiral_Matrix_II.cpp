class Solution {
public:

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    
    bool is_legal(int size,  vector<vector<int> > arr, int x, int y,  int direct) {
        int nx = x + dx[direct];
        int ny = y + dy[direct];
        if(nx < 0 || nx >= size || ny < 0 || ny >= size)
            return false;
        if(arr[nx][ny] != 0)
            return false;
        return true;
    }
    
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > grid;
        if(n == 0)
            return grid;
            
        int size = n;
        int direct = 0, cnt = 0;
        for(int i = 0; i < size; i++) {
            vector<int> tmp;
            for(int j = 0; j < size; j++) {
                tmp.push_back(0);
            }
            grid.push_back(tmp);
        }
        
        int x = 0, y = 0;
        
        while(true) {
            grid[x][y] = (++cnt);
            
            if(cnt >= n*n)
                break;
                
            if(!is_legal(size, grid, x, y, direct))
                direct = (direct + 1) % 4;
            x += dx[direct];
            y += dy[direct];
            
        } 
        
        return grid;
    }
};
