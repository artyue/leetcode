class Solution {
public:
    inline int getMin (int a, int b) {
    	return (a < b ? a : b);
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        if(row == 0) return 0;

        int max_col = row;
        int dp[row][max_col];

        for(int i = 0; i < max_col; i++)
        	dp[row-1][i] = triangle[row-1][i];

        for(int i = row - 2; i >= 0; i--)
        	for(int j = 0; j < i + 1; j++)
        		dp[i][j] = triangle[i][j] + getMin(dp[i+1][j], dp[i+1][j+1]);


        return dp[0][0];
    }
};