class Solution {
public:
	/* Subsets solution 1 */
	void subsetsRecursive(vector<int> &S, int cur, vector<vector<int> > &v, vector<int> &tmp, bool arr[]) {
		if(cur == S.size()) {
			for(int i = 0; i < cur; i++) {
				if(arr[i] == false) {
					tmp.push_back(S[i]);
				}
			}
			v.push_back(tmp);
			tmp.resize(0);
			return;
		}
		
		arr[cur] = true;
		subsetsRecursive(S, cur+1, v, tmp, arr);
		arr[cur] = false;
		subsetsRecursive(S, cur+1, v, tmp, arr);
	}

	vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > v;
		int size = S.size();
		if(size == 0)
			return v;

        sort(&S[0], &S[S.size()]);
		vector<int> tmp;
		bool arr[size];
		for(int i = 0; i < size; i++)
			arr[i] = false;

		subsetsRecursive(S, 0, v, tmp, arr);
		
		return v;
	}
	
	
	/* Subsets solution 2 */	
	/* S = {0, 1, 4}
	 *					 |-----{0,1}-----{0,1,4}
	 *        |----{0}---|
	 *        |          |-----{0,4}
	 *        |
	 * root---|----{1}---------{1,4}
	 *        |
	 *        |
	 *        |----{4}
	 * */
	void subsetsRecursive2(vector<int> &S, int cur_size, int cur_arr[], int cur_first,
                           vector<vector<int> > &v, vector<int> &tmp) {
        tmp.resize(0);
        for(int i = 0; i < cur_size; i++) {    
            tmp.push_back(cur_arr[i]);
        }
        v.push_back(tmp);
        
        for(int i = cur_first; i < S.size(); i++) {
            cur_arr[cur_size] = S[i];
            subsetsRecursive2(S, cur_size+1, cur_arr, i+1, v, tmp);
        }
    }
    
    vector<vector<int> > subsets2(vector<int> &S) { 
        vector<vector<int> > v;
		int size = S.size();
		if(size == 0)
			return v;

        sort(S.begin(), S.end());
		vector<int> tmp;
        int arr[size];
		subsetsRecursive2(S, 0, arr, 0, v, tmp);
		
		return v;
    }
	
};
