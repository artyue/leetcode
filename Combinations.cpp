class Solution {
public:

    void combineRecursive(vector<vector<int> > &v, int n, int cur_k, int start, vector<int> &tv) {
        if(cur_k == 0) {
            v.push_back(tv);
            return;
        }
        
        for(int i = start; i <= n; i++) {
            tv.push_back(i);
            combineRecursive(v, n, cur_k-1, i + 1, tv);
            tv.pop_back();
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > v;
        vector<int> tv;
        combineRecursive(v, n, k, 1, tv);
        return v;
    }
};
