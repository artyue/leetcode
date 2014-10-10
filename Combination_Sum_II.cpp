class Solution {
public:
	static bool myCmp(const int &a, const int &b) {
		return a < b;
	}

	bool isDup(vector<vector<int> > &v, vector<int> &tmp) {
		for(int i = 0; i < v.size(); ++i) {
			if(v[i] == tmp)
				return true;
		}
		return false;
	}

	void combinationSum2Recursion(int index, int cur_sum, int target, vector<int> tmp, 
								  vector<vector<int> > &v, vector<int> &num) {
		if(cur_sum == target) {
			if(!isDup(v, tmp)) {
				v.push_back(tmp);
			}
			return;
		}

		if(index >= num.size())
		  return;

		combinationSum2Recursion(index+1, cur_sum, target, tmp, v, num);

		if(cur_sum + num[index] <= target) {
			tmp.push_back(num[index]);
			combinationSum2Recursion(index+1, cur_sum+num[index], target, tmp, v, num);
        }
	}

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > v;
        int size = num.size();
        if(size == 0)
        	return v;

        sort(num.begin(), num.end(), myCmp);
        vector<int> tmp;
        combinationSum2Recursion(0, 0, target, tmp, v, num);
        return v;
    }
};