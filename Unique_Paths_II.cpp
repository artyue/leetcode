class Solution {
public:
	inline int getMax(int a, int b) {
		return ((a > b) ? a : b);
	}

	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int row = obstacleGrid.size();
		if(row == 0)
			return 0;
		int col = obstacleGrid[0].size();
		if(col == 0)
			return 0;

		int dp[row][col];
		memset(dp, 0, sizeof(dp));

		bool has_obstacle = false;
		for(int i = 0; i < col; i++) {
			if(obstacleGrid[0][i] == 1) {
				has_obstacle = true;
				dp[0][i] = 0;
			} else {
				if(!has_obstacle)
					dp[0][i] = 1;
				else
					dp[0][i] = 0;
			}
		}
		has_obstacle = false;
		for(int i = 0; i < row; i++) {
			if(obstacleGrid[i][0] == 1) {
				has_obstacle = true;
				dp[i][0] = 0;
			} else {
				if(!has_obstacle)
					dp[i][0] = 1;
				else
					dp[i][0] = 0;
			}
		}
		
		for(int i = 1; i < row; i++) {
			for(int j = 1; j < col; j++) {
				if(obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
				} else {
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				}
			}
		}
		
		return dp[row-1][col-1];
	}
};
