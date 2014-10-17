class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1)
            return 0;

        int size = prices.size(), max_profit = 0;
        int dp_forward[size+1], dp_backward[size+1];
        memset(dp_forward, 0, sizeof(dp_forward));
        memset(dp_backward, 0, sizeof(dp_backward));

        int prev_min = prices[0]; dp_forward[0] = 0;
        for(int i = 1; i < size; ++i) {
            if (dp_forward[i-1] > prices[i] - prev_min)
                dp_forward[i] = dp_forward[i-1];
            else
                dp_forward[i] = prices[i] - prev_min;
            prev_min = (prev_min > prices[i] ? prices[i] : prev_min);
        }

        int following_max = prices[size-1]; dp_backward[size-1] = 0;
        for (int i = size - 2; i >= 0; --i) {
            if (dp_backward[i+1] > following_max - prices[i])
                dp_backward[i] = dp_backward[i+1];
            else
                dp_backward[i] = following_max - prices[i];
            following_max = (following_max > prices[i] ? following_max : prices[i]);
        }

        for (int i = 0; i <= size - 1; ++i)
            if (max_profit < dp_forward[i] + dp_backward[i+1])
                max_profit = dp_forward[i] + dp_backward[i+1];

        return max_profit;
    }
};
