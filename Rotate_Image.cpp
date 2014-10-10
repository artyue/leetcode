class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int size = matrix.size();
		if(size == 1 || size == 0)
			return;
		for(int s = 0; s <= (size-1)/2; s++) {
			int times = (size-1) - s*2;
			for(int i = 0; i < times; i++) {
				int tmp = matrix[s][s+i];
				matrix[s][s+i] = matrix[(size-1)-(s+i)][s];
				matrix[(size-1)-(s+i)][s] = matrix[(size-1)-s][(size-1)-(s+i)];
				matrix[(size-1)-s][(size-1)-(s+i)] = matrix[s+i][(size-1)-s];
				matrix[s+i][(size-1)-s] = tmp;
			}
		}
		return;
	}
};
