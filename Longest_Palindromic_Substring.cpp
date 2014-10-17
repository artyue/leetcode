class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size == 0)
            return "";

        int dp[size][size], maxLen = 1, ps = 0, pe = 0;
        memset(dp, 0, sizeof(dp));
        for (int  i = 0; i < size; ++i)
            dp[i][i] = 1;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (i - j <= 1) {
                    dp[j][i] = (s[j] == s[i]);
                } else {
                    dp[j][i] = (dp[j+1][i-1] && (s[j] == s[i]));
                }
                if (dp[j][i]) {
                    if (i - j + 1 > maxLen) {
                        maxLen = i - j + 1;
                        ps = j; pe = i;
                    }
                }
            }
        }
        return s.substr(ps, pe-ps+1);
    }
};
