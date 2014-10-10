class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
    	vector<vector<int> > v;
		if(num.size() == 0)
			return v;

        sort(num.begin(), num.end());

        int flag[num.size()], arr[num.size()];
        memset(flag, 0, sizeof(flag));

        permuteUniqueRecursion(num, num.size(), num.size(), flag, arr, v);
        return v;
    }

    void permuteUniqueRecursion(vector<int> &num, int size, int remain, int flag[], int arr[], vector<vector<int> > &v) {
    	if(remain == 0) {
    		vector<int> tmp;
    		for(int i = 0; i < size; ++i)
    			tmp.push_back(arr[i]);
    		v.push_back(tmp);
    		return;
    	}
    	int last;
    	for(int i = 0; i < size; ++i) {
    		if(i > 0 && num[i] == num[i-1] && flag[i-1] == 0)
    		//if(i > 0 && num[i] == last)
    			continue;
    		if(flag[i] == 0) {
    			flag[i] = 1;
    			last = (arr[size-remain] = num[i]);
    			permuteUniqueRecursion(num, size, remain-1, flag, arr, v);
    			flag[i] = 0;
    		}
    	}
    }
};
