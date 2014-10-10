class Solution {
public:
    bool isDigit(char c) {
    	if('a' <= c && c <= 'z')
    		return true;
    	if('A' <= c && c <= 'Z')
    		return true;
    	if('0' <= c && c <= '9')
    		return true;
    	return false;
    }

    bool isSameDigit(char a, char b) {
    	if('0' <= a && a <= '9' && '0' <= b && b <= '9') {
    		if(a == b)
    			return true;
    		else
    			return false;
    	}
    	if(a == b || abs(a - b) == abs('A' - 'a'))
    		return true;
    	return false;
    }

    bool isPalindrome(string s) {
        int size = s.size();
        if(size == 0)
        	return true;

        int f = 0, r = size - 1;
        while(f < size) {
        	if(isDigit(s[f]) && isDigit(s[r])) {
        		if(!isSameDigit(s[f], s[r])) {
        			return false;
        		} else {
        			++f;
        			--r;
        		}
        	}
        	if(!isDigit(s[f]))
        		++f;
        	if(!isDigit(s[r]))
        		--r;
        }
        return true;
    }
};