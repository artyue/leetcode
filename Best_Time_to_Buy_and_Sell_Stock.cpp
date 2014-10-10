class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if(prices.size() == 0 || prices.size() == 1)
			return 0;
		int MAX_SELL[prices.size()], dp[prices.size()];
		int MAX = -99999999;

		MAX_SELL[prices.size() - 1] = prices.back();
		
		for(int i = prices.size() - 2; i >= 0; i--) {
			if(prices[i] > MAX_SELL[i+1])
				MAX_SELL[i] = prices[i];
			else
				MAX_SELL[i] = MAX_SELL[i+1];
			dp[i] = MAX_SELL[i] - prices[i];
			if(MAX < dp[i])
				MAX = dp[i];
		}

		return MAX;
	}
};
