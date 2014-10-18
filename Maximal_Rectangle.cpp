class Solution {
public:
    int largestRectangleArea(vector<int> &h) {
        int res = 0;
        vector<int> height = h;
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
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        int row = matrix.size();
        if (row == 0)
            return res;
        int col = matrix[0].size();
        if (col == 0)
            return res;
        
        vector<int> v(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '0')
                    v[j] = 0;
                else
                    ++v[j];
            }
            res = max(res, largestRectangleArea(v));
        }
        return res;
    }
};
