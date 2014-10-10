class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        if(size == 0)
        	return;

        bool isMax = true;
        for(int i = size - 1; i > 0; --i) {
        	if(num[i] > num[i-1]) {
        		isMax = false;
        		int j, goal_index = i;
        		for(j = i+1; j < size; ++j) {
        			if(num[j] > num[i-1] && num[j] < num[goal_index])
        				goal_index = j;
        		}

        		int tmp = num[i-1];
        		num[i-1] = num[goal_index];
        		num[goal_index] = tmp;
        		sort(num.begin()+i, num.end());
        		break;
        	}
        }

        if(isMax)
        	sort(num.begin(), num.end());
    }
};