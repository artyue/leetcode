class Solution {
public:
    static bool isLegal(int last_row, int next_c, int queen[]) {
    	for(int r = 0; r <= last_row; ++r) {
    		if(next_c == queen[r])
    			return false;
    		if(abs(next_c - queen[r]) == abs(last_row + 1 - r))
    			return false;
    	}
    	return true;
    }

    static void solveNQueensRecursion(int n, int cur_row, int queen[], vector<vector<string> > &v) {
    	if(cur_row == n) {
    		vector<string> tmp;
    		for(int r = 0; r < n; ++r) {
    			string cur_row_s;
    			for(int c = 0; c < n; ++c) {
    				if(queen[r] == c)
    					cur_row_s += 'Q';
    				else
    					cur_row_s += '.';
    			}
    			tmp.push_back(cur_row_s);
    		}
    		v.push_back(tmp);
    		return;
    	}

    	for(int c = 0; c < n; ++c) {
    		if(isLegal(cur_row-1, c, queen)) {
    			queen[cur_row] = c;
    			solveNQueensRecursion(n, cur_row+1, queen, v);
    		}
    	}
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > v;
        if(n == 0)
        	return v;

        int queen[n];
        solveNQueensRecursion(n, 0, queen, v);
        return v;
    }
};