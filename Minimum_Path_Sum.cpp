class Solution {
public:
	const int MAX_NUM = 99999999;
	const int dx[4] = {0, 0, -1, 1};
	const int dy[4] = {-1, 1, 0, 0};

	inline int getMin(int a, int b) {
		return ((a < b) ? a : b);
	}

	inline bool is_legal(int x, int y, int r, int c) {
		if(x >= 0 && x < r && y >= 0 && y < c)
			return true;
		return false;
	}
		
	int minPathSum(vector<vector<int> > &grid) {
		int row = grid.size();
		if(row == 0)
			return 0;
		int col = grid[0].size();
		if(col == 0)
			return 0;
		
		vector<vector<int> > dp(grid);
		for(int i = 0; i < row; i++)
			for(int j = 0; j < col; j++)
				dp[i][j] = MAX_NUM;

		/* initialization */
		dp[0][0] = grid[0][0];
		for(int i = 1; i < col; i++)
			dp[0][i] = (dp[0][i-1] + grid[0][i]);
		for(int i = 1; i < row; i++)
			dp[i][0] = (dp[i-1][0] + grid[i][0]);

		for(int i = 1; i < row; i++) {
			for(int j = 1; j < col; j++) {
				dp[i][j] = getMin(dp[i-1][j], dp[i][j-1]) + grid[i][j];
			}
		}
		
		return dp[row-1][col-1];
    }
};
