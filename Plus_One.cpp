class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		int size = digits.size();
		if(size == 0)
			return digits;
		
		bool bonus = true;
		for(int i = size-1; i >= 0; i--) {
			int tmp = digits[i];
			if(bonus) {
				tmp += 1;
				if(tmp >= 10) {
					digits[i] = (tmp = 0);
					bonus = true;
					if(i == 0) {
						vector<int> ans;
						ans.push_back(1);
						for(int i = 0; i < size; i++)
							ans.push_back(digits[i]);
						return ans;
					}
				} else {
					digits[i] = tmp;
					return digits;
				}
			}
		}
	}
};
