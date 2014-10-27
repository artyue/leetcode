class Solution {
public:
    int string2Int (string &s) {
        size_t size = s.size();
        int res = 0, i = 0, isNeg = 0;
        if (s[0] == '-')
            isNeg = (++i);
        for (; i < size; ++i)
            res = res * 10 + (s[i] - '0');
        return (isNeg ? (-res) : res);
    }
    
    int evalRPN(vector<string> &tokens) {
        size_t size = tokens.size();
        if (size == 0) return 0;
        
        stack<int> stk;
        for (int i = 0; i < size; ++i) {
            if (tokens[i].size() > 1 || (tokens[i][0] >= '0' && tokens[i][0] <= '9')) {
                stk.push(string2Int(tokens[i]));
            } else {
                int a, b;
                b = stk.top(); stk.pop();
                a = stk.top(); stk.pop();
                switch (tokens[i][0]) {
                    case '+':
                        stk.push(a+b);
                        break;
                    case '-':
                        stk.push(a-b);
                        break;
                    case '*':
                        stk.push(a*b);
                        break;
                    case '/':
                        stk.push(a/b);
                        break;
                    default:
                        break;
                }
            }
        }
        return stk.top();
    }
};
