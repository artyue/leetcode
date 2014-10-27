class Solution {
public:
    int candy(vector<int> &ratings) {
        size_t size = ratings.size();
        if (size == 0)
            return 0;
        
        vector<int> candys(size, 1);
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i-1])
                candys[i] = candys[i-1] + 1;
        }
        //for (int i = 0; i < size; ++i) { cout << candys[i] << " "; }cout << endl;
        int res = candys[size-1];
        for (int i = (int)size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1])
                if (candys[i] <= candys[i+1])
                    candys[i] = candys[i+1] + 1;
            res += candys[i];
        }
        //for (int i = 0; i < size; ++i) { cout << candys[i] << " "; }cout << endl;
        return res;
    }
};
