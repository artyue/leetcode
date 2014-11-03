class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict_old) {
        vector<string> v;
        int size = s.size();
        if (size == 0 || dict_old.size() == 0)
            return v;
        
        /* Word filtering */
        unordered_set<string> dict;
        for (auto word : dict_old) {
            if (word.size() > size)
                continue;
            for (int i = 0; i <= size-word.size(); ++i) {
                if (word == s.substr(i, word.size())) {
                    dict.insert(word);
                    break;
                }
            }
        }
        
		/* DP initilization */
        vector<vector<int> > dp;
        dp.resize(size+1);
        for (auto w : dict) {
            if (s.substr(0, w.size()) == w)
                dp[w.size()].push_back(0);
        }
        
		/* DP */
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string cur = s.substr(j, i - j);
                for (auto w : dict) {
                    if (w == cur && dp[j].size() > 0) {
                        dp[i].push_back(j);
                    }
                }
            }
        }
        
		/* Genetate all of the answer strings */
        vector<vector<string> > res;
        res.resize(size+1);
        res[s.size()].push_back("");
        for (int i = size; i >= 0; --i) {
            for (auto cur_string : res[i]) {
                for (auto prev_id : dp[i]) {
                    res[prev_id].push_back(s.substr(prev_id, i-prev_id) + (i == s.size() ?  "" : " ") + cur_string);
                }
            }
        }
        
        return res[0];
    }
};
