class Solution {
public:
	inline int getMin(int a, int b) {
		return ((a < b) ? a : b);
	}

	int maxArea(vector<int> &height) {
		int size = height.size();
		if(size == 0 || size == 1)
			return 0;

		int MAX_VAL = -1;
		int i = 0, j = size - 1;
		while(i < j) {
			int tmp = (j - i) * getMin(height[i], height[j]);
			MAX_VAL = (MAX_VAL < tmp) ? tmp : MAX_VAL;
			if(height[i] > height[j])
				j--;
			else
				i++;
		}

		return MAX_VAL;
	}
};
