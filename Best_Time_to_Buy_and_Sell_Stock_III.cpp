class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size <= 1)
        	return 0;

        int curMin = prices[0], curMax = prices[0], maxProfitVal = 0; 
        for(int i = 1; i < size; ++i) {
        	if(prices[i] < curMin) {
        		curMin = curMax = prices[i];
        	}
        	if(prices[i] > curMax) {
        		curMax = prices[i];
        		maxProfitVal = (maxProfitVal < (curMax - curMin) ? (curMax - curMin) : maxProfitVal);
        	}
        }

        return maxProfitVal;
    }
};
