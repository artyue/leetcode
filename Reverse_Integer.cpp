class Solution {
public:
	int reverse(int x) {
		if(x == 0)
			return 0;

		int ans = 0;
		bool is_neg = false;

		if(x < 0) 
			is_neg = true;

		x = abs(x);
		while(x != 0) {
			int tmp = x % 10;
			ans = ans * 10 + tmp;
			x /= 10;
		}

		if(is_neg)
			return (ans * (-1));
		else
			return ans;
    }
};
