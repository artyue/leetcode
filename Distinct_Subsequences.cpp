class Solution {
public:
    int numDistinct(string S, string T) {
        int size_S = S.size();
        int size_T = T.size();

        if(size_S < size_T)
        	return 0;

        int dp[size_T+5][size_S+5];
        for(int s = 0; s <= size_S; ++s)
        	dp[0][s] = 1;

        for(int t = 0; t <= size_T; ++t)
        	dp[t][0] = 0;

        dp[0][0] = 1;

        for(int t = 1; t <= size_T; ++t) {
        	for(int s = 1; s <= size_S; ++s) {
        		dp[t][s] = dp[t][s-1];
        		if(T[t-1] == S[s-1]) // Be careful the -1 here
        			dp[t][s] += dp[t-1][s-1];
        	}
        }

        return dp[size_T][size_S];
    }
};
