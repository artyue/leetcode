class Solution {
public:
	bool isPalindrome(string &s, int sp, int ep) {
    	int i = sp, j = ep;
    	while(i < j) {
    		if(s[i++] != s[j--]) {
    			return false;
    		}
    	}
    	return true;
    }

    void partitionRecursion(int head, string &s, vector<string> &tmp, vector<vector<string> > &v) {
    	if(head == s.size()) {
    		v.push_back(tmp);
    		return;
    	}

    	for(int i = head; i < s.size(); ++i) {
    		if(isPalindrome(s, head, i)) {
    			tmp.push_back(s.substr(head, i-head+1));
    			partitionRecursion(i+1, s, tmp, v);
    			tmp.pop_back();
    		}
    	}
    }

    vector<vector<string> > partition(string s) {
        int size = s.size();
        vector<vector<string> > v;
        if(size == 0)
        	return v;

        vector<string> tmp;
        partitionRecursion(0, s, tmp, v);
        return v;
    }
};