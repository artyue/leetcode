class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int size = strs.size();
        if(size == 0) return "";
        if(size == 1) return strs[0];
        
        int s = 0;
        string ans = "";
        while(true) {
            char cur_c = strs[0][s];
            for(int i = 1; i < size; i++) 
                if(strs[i].size() == s || strs[i][s] != cur_c)
                    return ans;
            ans += cur_c;
            s++;
        }
    }
};
