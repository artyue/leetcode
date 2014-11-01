class Solution {
public:
    int minCut(string s) {
        size_t size = s.size();
        if (size <= 1)
            return 0;
        
        /* dp[i][j]: 字符串子串[i,j]是否为回文串 */
        int (*dp)[2000] = new int[2000][2000];
        memset(dp, 0, sizeof(dp));
        for (int  i = 0; i < size; ++i)
            dp[i][i] = 1;
        
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (i - j <= 1)
                    dp[j][i] = (s[j] == s[i]);
                else
                    dp[j][i] = (dp[j+1][i-1] && (s[j] == s[i]));
            }
        }

        /* cuts[i]: 对字符串子串[0,i]的最小切数，使得切成所有子串都为回文串 */
        int cuts[size];
        cuts[0] = 0;
        for (int i = 1; i < size; ++i) {
            if (dp[0][i] == 1) {
                cuts[i] = 0;
            } else {
                cuts[i] = i;
                for (int s = 0; s < i; ++s) {
                    if (dp[s+1][i] == 1) {
                        cuts[i] = min(cuts[i], cuts[s] + 1);
                    }
                }
            }
        }
        delete []dp;
        return cuts[size-1];
    }
};
