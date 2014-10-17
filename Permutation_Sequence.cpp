class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        if (n == 0)
            return res;

        int isPicked[10], jieCheng[10];
        memset(isPicked, 0, sizeof(isPicked));
        jieCheng[0] = 1;
        for (int i = 1; i <= n; ++i) {
            jieCheng[i] = jieCheng[i-1] * i;
        }

        int remain = k;
        for (int cur_index = 1; cur_index <= n; ++cur_index) {
            int count = 0;
            while (jieCheng[n-cur_index] * count < remain) {
                ++count;
            }
            int ct = 0, i;
            for (i = 1; i <= n; ++i) {
                if (isPicked[i] == 0) {
                    ++ct;
                } else {
                    continue;
                }
                if (ct >= count)
                    break;
            }
            res += ('0' + i);
            isPicked[i] = 1;
            remain -= (jieCheng[n-cur_index] * (count - 1));
        }

        return res;
    }
};
