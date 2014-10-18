class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        
        string res = "";
        int s1 = num1.size(), s2 = num2.size(), product[s1+s2-1];
        memset(product, 0, sizeof(product));
        for (int j = s2 - 1; j >= 0; --j)
            for (int i = 0; i < s1; ++i)
                product[i + j] += (num1[i] - '0') * (num2[j] - '0');
        
        int forward = 0;
        for (int i = s1 + s2 - 2; i >= 0; --i) {
            product[i] += forward;
            if (product[i] >= 10) {
                forward = product[i] / 10;
                product[i] -= (forward * 10);
            } else {
                forward = 0;
            }
            res = (char)('0' + product[i]) + res;
        }
        while (forward) {
            res = (char)(forward % 10 + '0') + res;
            forward /= 10;
        }
        
        return res;
    }
};
