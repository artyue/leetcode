class Solution {
public:
    string minWindow(string S, string T) {
        string res = "";
        int needChar[256], foundChar[256];
        memset(needChar, 0, sizeof(needChar));
        memset(foundChar, 0, sizeof(foundChar));
        for (int i = 0; i < T.size(); ++i)
            ++needChar[T[i]];
        
        int s = 0, e = 0, foundListCount = 0, minWin = 9999999;
        for (; e < S.size(); ++e) {
            char cur_char = S[e];
            /* The cur_c is not in the string T */
            if (needChar[cur_char] == 0)
                continue;
            
            /* Find a new char in T that is first included in the window */
            if (foundChar[cur_char] < needChar[cur_char])
                ++foundListCount;
            
            ++foundChar[cur_char];
            
            /* The window currently contains all chars in string T */
            if (foundListCount == T.size()) {
                /* Try to move forward the position of `s` */
                while (needChar[S[s]] == 0 || foundChar[S[s]] > needChar[S[s]]) {
                    --foundChar[S[s]];
                    ++s;
                }
                
                /* Update the minWin and the window */
                if (e - s + 1 < minWin) {
                    minWin = e - s + 1;
                    res = S.substr(s, minWin);
                }
            }
        }
        
        return res;
    }
};
