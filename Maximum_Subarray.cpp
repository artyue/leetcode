class Solution {
public:
	int maxSubArray(int A[], int n) {
		int MAX;
		int dp[n + 5];
		MAX = dp[0] = A[0];

		for(int i = 1; i < n; i++) {
			if(dp[i-1] > 0)
				dp[i] = dp[i - 1] + A[i];
			else
				dp[i] = A[i];
			MAX = (MAX < dp[i]) ? dp[i] : MAX;
		}
		return MAX;
    }
};
