class Solution {
public:
    void subsetsWithDupRecursive(vector<int> &S, vector<vector<int> > &v, int cur_first, int cur_size, int cur_arr[]) {
        vector<int> tmp;
        for(int i = 0; i < cur_size; i++)
            tmp.push_back(cur_arr[i]);
        v.push_back(tmp);
        
        bool is_first = true;
        for(int i = cur_first; i < S.size(); i++) {
            if(is_first || (i > 0 && S[i] != S[i-1])) {
                is_first = false;
                cur_arr[cur_size] = S[i];
                subsetsWithDupRecursive(S, v, i+1, cur_size+1, cur_arr);
            } 
        }
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > v;
        if(S.size() == 0)
            return v;
        
        sort(S.begin(), S.end());
        int cur_arr[S.size()];
        subsetsWithDupRecursive(S, v, 0, 0, cur_arr);
        return v;
    }
};