class Solution {
public:
	static bool myCmp(const int &a, const int &b) {
		return a > b;
	}

	static vector<int> sortVector(vector<int> &cur) {
		vector<int> ans = cur;
		sort(ans.begin(), ans.end());
		return ans;
	}

    void combinationSumRecursion(vector<int> &candidates, int target, vector<vector<int> > &v,
    							 vector<int> &cur, int avi) {
    	if(target == 0) {
    		v.push_back(sortVector(cur));
    		return;
    	}

    	if(target < 0)
    		return;

    	for(int i = avi; i < candidates.size(); i++) {
    		cur.push_back(candidates[i]);
    		combinationSumRecursion(candidates, target-candidates[i], v, cur, i);
    		cur.pop_back();
    	}
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > v;
        int size = candidates.size();
        if(size == 0)
        	return v;

        sort(candidates.begin(), candidates.end(), myCmp);
        vector<int> cur;
        combinationSumRecursion(candidates, target, v, cur, 0);
        return v;
    }
};