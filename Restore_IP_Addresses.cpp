class Solution {
public:
    bool digitValid(string s) {
        if (s.size() > 1 && s[0] == '0')
            return false;
        
        int num = 0;
        for (int i = 0; i < s.size(); ++i)
            num = num * 10 + (s[i] - '0');
        
        if(num < 0 || num > 255)
            return false;
        return true;
    }
    
    void restoreIpAddressesRecursion(string &s, int pos, vector<string> &tmp, vector<string> &v) {
        if(tmp.size() == 4 && pos == s.size()) {
            v.push_back(tmp[0] + '.' + tmp[1] + '.' + tmp[2] + '.' + tmp[3]);
            return;
        }
        
        if(tmp.size() < 4) {
            for (int len = 1;  pos + len - 1 < s.size() && len <= 3; ++len) {
                string newPart = s.substr(pos, len);
                if (digitValid(newPart)) {
                    tmp.push_back(newPart);
                    restoreIpAddressesRecursion(s, pos+len, tmp, v);
                    tmp.pop_back();
                }
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        if (s.size() < 4 || s.size() > 12)
            return v;
        
        vector<string> tmp;
        restoreIpAddressesRecursion(s, 0, tmp, v);
        return v;
    }
};
