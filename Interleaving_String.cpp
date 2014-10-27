class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t ss1, ss2, ss3;
        ss1 = s1.size();
        ss2 = s2.size();
        ss3 = s3.size();
        if (ss1 + ss2 != ss3)   return false;
        if (ss1 == 0)   return (s2 == s3);
        if (ss2 == 0)   return (s1 == s3);
        
        int dp[ss1+1][ss2+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= ss1; ++i) {
            if (s1[i-1] == s3[i-1])
                dp[i][0] = 1;
            else
                break;
        }
        for (int i = 1; i <= ss2; ++i) {
            if (s2[i-1] == s3[i-1])
                dp[0][i] = 1;
            else
                break;
        }
        
        for (int i = 1; i <= ss1; ++i) {
            for (int j = 1; j <= ss2; ++j) {
                dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1]));
                dp[i][j] = dp[i][j] || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        
        return dp[ss1][ss2];
    }
};
