class Solution {
public:
    int longestValidParentheses(string s) {
        size_t size = s.size();
        if (size < 2)
            return 0;
        
        vector<int> dp(size+1);
        int maxCt = 0;
        /* dp[i]: the length of valid parentheses sub-string ended with s[i] */
        for (size_t i = 2; i <= size; ++i) {
            if (s[i-1] == ')') {
                if (s[i-2] == '(') {
                    dp[i] = dp[i-2] + 2;
                } else {
                    if (dp[i-1] > 0) {
                        int forward = dp[i-1];
                        if (i - forward > 1 && s[i-forward-2] == '(') {
                            dp[i] = forward + 2;
                            if (i - forward - 1 > 1)
                                dp[i] += dp[i-forward-2];
                        }
                    }
                }
            }
            if (dp[i] > maxCt)
                maxCt = dp[i];
        }
        return maxCt;
    }
};
