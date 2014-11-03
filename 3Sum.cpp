class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > v;
        size_t size = num.size();
        if (size < 3)
            return v;
        
        sort(num.begin(), num.end());
        for (int i = 0; i < size - 2; ++i) {
            if (num[i] > 0)
                break;
            if (i > 0 && num[i] == num[i-1])
                continue;
            size_t p = i + 1, s = size - 1;
            while (p < s) {
                if (num[i] + num[p] + num[s] == 0) {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[p]);
                    tmp.push_back(num[s]);
                    v.push_back(tmp);
                    ++p; --s;
                    while (num[p] == num[p-1] && p < s)
                        ++p;
                    while (num[s] == num[s+1] && p < s)
                        --s;
                } else if (num[i] + num[p] + num[s] > 0) {
                    --s;
                } else {
                    ++p;
                }
            }
        }
        
        return v;
    }
};
