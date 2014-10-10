class Solution {
public:
	/* O(logN) */
	int find_row(vector<vector<int> > &matrix, int s, int e, int target) {
		if(matrix[s][0] > target)
			return -1;
		
		int i = s, j = e;
		
		while(true) {
			if(j - i == 1) {
				if(target < matrix[i][0]) {
					if(i > 0)
						return (i - 1);
					else
						return -1;
				} else if(target >= matrix[j][0]) {
					return j;
				} else {
					return i;
				}
			}
			if(i == j) {
				return i;
			}
			int mid = i + (j - i) / 2;
			if(matrix[mid][0] == target)
				return mid;
			else if(matrix[mid][0] > target)
				j = mid;
			else
				i = mid;
		}
		return i;
	}

	/* O(n) */
	int find_row2(vector<vector<int> > &matrix, int s, int e, int target) {
		if(s == e) {
			if(matrix[s][0] <= target)
				return s;
			else
				return -1;
		}

		if(matrix[s][0] > target)
			return -1;

		for(int i = s; i < e; i++) {
			if(matrix[i][0] <= target && matrix[i+1][0] > target)
				return i;
			if(matrix[i][0] > target)
				return -1;
		}
		if(matrix[e][0] <= target)
			return e;
		return -1;
	}

	bool find_element(vector<int> &row, int s, int e, int target) {
		int i = s, j = e;
		while(true) {
			if(j - i == 1) {
				if(row[i] == target || row[j] == target)
					return true;
				return false;
			}
			if(i == j) {
				if(row[i] == target)
					return true;
				return false;
			}
			int mid = i + (j - i) / 2;
			if(row[mid] == target)
				return true;
			else if(row[mid] > target)
				j = mid - 1;
			else
				i = mid + 1;
		}
		return false;
	}

	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int row = matrix.size();
		if(row == 0)
			return false;
		int col = matrix[0].size();
		if(col == 0)
			return false;
		
		int target_row = find_row(matrix, 0, row-1, target);
		//int target_row = find_row2(matrix, 0, row-1, target);
		if(target_row == -1)
			return false;

		return find_element(matrix[target_row], 0, col-1, target);
	}
};
