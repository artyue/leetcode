class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        size_t size_s = strlen(s), size_p = strlen(p);
        int dp[size_s+1][size_p+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        for (int i = 1; i <= size_p; ++i) {
            /*  s: 空串
                p: a*b*c*d*
                结果：匹配
             */
            if (p[i-1] == '*')
                dp[0][i] = dp[0][i-2];
        }
        for (int i = 1; i <= size_s; ++i) {
            char cur_s = s[i-1];
            for (int j = 1; j <= size_p; ++j) {
                char cur_p = p[j-1];
                if (cur_s == cur_p || cur_p == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (cur_p == '*') {
                    if (cur_s != p[j-2] && p[j-2] != '.' )
                        dp[i][j] = dp[i][j-2]; /* 此时*号带着前一个字符“隐身” */
                    else
                        dp[i][j] = dp[i][j-2] || dp[i-1][j]; /* 难点：可以选择“*号带着前一个字符隐身（*号放弃匹配cur_s）”，也可以选择（*号匹配cur_s）。后者的理解是难点（*一旦可以匹配，则可以连续匹配下去） */
                }
            }
        }
        return dp[size_s][size_p];
    }
    
};
