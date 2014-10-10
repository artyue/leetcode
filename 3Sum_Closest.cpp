class Solution {
public:
    inline int abs3(int a, int target) {
        return abs(a - target);
    }

    inline int get3Sum(int f, int s, int t, vector<int> &num) {
        return (num[f] + num[s] + num[t]);
    }

    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        if(size < 3) return 0;

        sort(num.begin(), num.end());
        int ret_sum = 999999;

        for(int f = 0; f <= size - 3; f++) {
            int s = f + 1, t = size - 1;
            while(s < t) {
                int tmp_sum = get3Sum(f, s, t, num);
                if(abs3(tmp_sum, target) < abs3(ret_sum, target))
                    ret_sum = tmp_sum;

                if(tmp_sum == target)
                    return target;
                else if(tmp_sum < target)
                    s++;    
                else if(tmp_sum > target)
                    t--;
            }
        }

        return ret_sum;
    }
};