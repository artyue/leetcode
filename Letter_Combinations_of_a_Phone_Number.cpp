class Solution {
public:
	void letterCombinationsRecursion(string &digits, int cur_pos, string tmp, 
									 vector<string> &v, string dig_map[10]) {
		if(cur_pos >= digits.size()) {
			v.push_back(tmp);
			return;
		}

		for(int i = 0; i < dig_map[digits[cur_pos]-'0'].size(); ++i) {
			letterCombinationsRecursion(digits, cur_pos+1, tmp+dig_map[digits[cur_pos]-'0'][i], v, dig_map);
		}
	}

    vector<string> letterCombinations(string digits) {
        vector<string> v;
        int size = digits.size();
        if(size == 0) {
        	v.push_back("");
        	return v;
        }

        string dig_map[10] = {" ",
        					  "",
    						  "abc",
    						  "def",
    						  "ghi",
    						  "jkl",
    						  "mno",
    						  "pqrs",
    						  "tuv",
    						  "wxyz"};

    	letterCombinationsRecursion(digits, 0, "", v, dig_map);
    	return v;
    }
};