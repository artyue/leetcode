class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> v;
        if (S.size() == 0 || L.size() == 0)
            return v;
        
        int S_size = (int)S.size();
        int L_size = (int)L.size();
        int word_size = (int)L[0].size();
        unordered_map<string, int> dict;
        unordered_map<string, int> find_log;
        
        for (auto i : L)
            ++dict[i];
    
        for (int i = 0; i <= S_size - word_size * L_size; ++i) {
            find_log.clear();
            int j = 0;
            for (; j < L_size; ++j) {
                string cur = S.substr(i+j*word_size, word_size);
                if (dict.count(cur)) {
                    if (find_log[cur] < dict[cur])
                        ++find_log[cur];
                    else
                        break;
                } else
                    break;
            }
            if (j == L_size)
                v.push_back(i);
        }
        
        return v;
    }
};
