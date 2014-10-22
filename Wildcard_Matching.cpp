class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        stack<const char *> stk_s, stk_p;
        const char *is = s, *ip = p;
        while (*is) {
            if (*is == *ip || *ip == '?') {
                ++is; ++ip;
                continue;
            }
            if (*ip == '*'){        /* 找到一个新的可回溯点 */
                stk_p.push(ip++);
                stk_s.push(is);
                continue;
            }
            if (!stk_p.empty()) {   /* 没匹配到，回溯 */
                is = stk_s.top(); stk_s.pop(); stk_s.push(++is);
                ip = stk_p.top(); ++ip;
                continue;
            }
            return false;
        }
        while (*ip == '*')
            ++ip;
        
        return (*ip == '\0');
    }
};
