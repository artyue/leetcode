class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        char *p1 = &(path[0]), *p2 = p1 + 1;
        string cur = "";
        while(*p2 != '\0') {
            if (*p2 == '/') {
                if (p2 - p1 > 1) {
                    if (cur == ".") {
                        ;
                    } else if (cur == "..") {
                        if (!stk.empty())
                            stk.pop();
                    } else {
                        stk.push(cur);
                    }
                }
                p1 = p2++;
                cur = "";
            } else {
                cur += *p2;
                ++p2;
            }
        }
        if(cur != "" && cur != "." && cur != "..")
            stk.push(cur);
        else if (cur == "..")
            if (!stk.empty())
                stk.pop();
        
        string res = "";
        while (!stk.empty()) {
            res = ('/' + stk.top()) + res;
            stk.pop();
        }
        
        if (res == "")
            return "/";
        return res;
    }
};
