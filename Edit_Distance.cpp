class Solution {
public:
    int getMin(int a, int b) {
    	return (a > b ? b : a);
    }

    int minDistance(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();

        if(s1 == 0 || s2 == 0)
        	return (s1 + s2);

        int dp[s1+5][s2+5];
        memset(dp, 0, sizeof(dp));

        for(int i = 0; i <= s1; ++i)
        	dp[i][0] = i;
        for(int j = 0; j <= s2; ++j)
        	dp[0][j] = j;

        for(int i = 1; i <= s1; ++i) {
        	for(int j = 1; j <= s2; ++j) {
        		if(word1[i-1] == word2[j-1]) {
        			dp[i][j] = dp[i-1][j-1];
        		} else {
        			dp[i][j] = getMin(getMin(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
        		}
        	}
        }

        return dp[s1][s2];
    }
};
