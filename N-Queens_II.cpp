class Solution {
public:
	int totalNQueens(int n) {
		int ans = 0;
		int q_col[n+1];
		memset(q_col, 0, sizeof(q_col));
		totalNQueensRecursive(n, 1, ans, q_col);
		return ans;
	}

	void totalNQueensRecursive(int size, int cur, int &cnt, int q_col[]) {
		if(cur > size) {
			cnt++;
			return;
		}
		for(int i = 1; i <= size; i++) {
			if(is_illegal(cur, i, q_col)) {
				q_col[cur] = i;
				totalNQueensRecursive(size, cur+1, cnt, q_col);
				q_col[cur] = 0;
			}
		}
	}

	bool is_illegal(int cur, int col, int q_col[]) {
		for(int i = 1; i <= cur-1; i++) {
			if(col == q_col[i])
				return false;
			if(abs(cur - i) == abs(col - q_col[i]))
				return false;
		}
		return true;
	}
};
