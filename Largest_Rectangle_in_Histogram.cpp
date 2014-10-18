class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        height.push_back(0);
        stack<int> H, L;
        for (vector<int>::iterator iter = height.begin(); iter != height.end(); ++iter) {
            int cur_height = *iter, len = 0;
            while (!H.empty() && H.top() > cur_height) {
                len += L.top();
                res = max(res, H.top() * len);
                H.pop();
                L.pop();
            }
            H.push(cur_height);
            L.push(++len);
        }
        return res;
    }
};
