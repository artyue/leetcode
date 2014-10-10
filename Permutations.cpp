class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > v;
		if(num.size() == 0)
			return v;
		int flag[num.size()], arr[num.size()];
		memset(flag, 0, sizeof(flag));
		permuteRecursive(num.size(), num.size(), num, flag, arr, v);
		return v;
	}

	void permuteRecursive(int size, int remain, vector<int> &num, int flag[], int arr[], vector<vector<int> > &v) {
		if(remain == 0) {
			vector<int> tmp;
			for(int i = 0; i < size; i++)
				tmp.push_back(arr[i]);
			v.push_back(tmp);
			return;
		}
		
		for(int i = 0; i < size; i++) {
			if(flag[i] == 0) {
				flag[i] = 1;
				arr[size-remain] = num[i];
				permuteRecursive(size, remain-1, num, flag, arr, v);
				flag[i] = 0;
			}
		}
	}
};
