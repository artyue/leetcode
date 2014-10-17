class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0)
            return true;
        if (dict.size() == 0)
            return false;

        int possible[s.size()];
        memset(possible, 0, sizeof(possible));
        
        for (int i = 0; i < s.size(); ++i) {
            if (dict.find(s.substr(0, i+1)) != dict.end()) {
                possible[i] = 1;
            } else {
                for (int k = 0; k < i; ++k) {
                    if (possible[k] && (dict.find(s.substr(k+1, i-k)) != dict.end())) {
                        possible[i] = 1;
                        break;
                    }
                }
            }
        }
        return possible[s.size()-1];
    }
};
