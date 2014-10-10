class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if(n == 0) {
			vector<string> v(0);
			return v;
		}
		vector<string> v;
		generateParenthesisRecursive(n, n, "", v);
		return v;
	}
	
	void generateParenthesisRecursive(int lp_remain, int rp_remain, string s, vector<string> &v) {
		if(lp_remain == 0 && rp_remain == 0) {
			v.push_back(s);
			return;
		}
		if(lp_remain > 0)
			generateParenthesisRecursive(lp_remain-1, rp_remain, s+"(", v);
		if(lp_remain < rp_remain)
			generateParenthesisRecursive(lp_remain, rp_remain-1, s+")", v);
	}
};
