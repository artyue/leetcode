class Solution {
public:
	void Reverse(string &a) {
		int i = 0, j = a.size() - 1;
        while(i < j) {
            char t = a[i];
            a[i] = a[j];
            a[j] = t;   
            i++; j--; 
        }
	}

    string addBinary(string a, string b) {
    	Reverse(a); Reverse(b);
        string ans = (a.size() > b.size() ? a : b);
        int step = ans.size();
        int small_size = (a.size() > b.size() ? b.size() : a.size());
        int i = 0, j = a.size() - 1;

        int forward_one = 0;
        for(int i = 0; i < step; ++i) {
        	if(i < small_size) {
        		int dig_a = a[i] - '0', dig_b = b[i] - '0';
        		if(dig_a + dig_b == 0) {
        			if(forward_one == 1) 
        				ans[i] = '1';
        			else
        				ans[i] = '0';
        			forward_one = 0;
        		} else if(dig_a + dig_b == 1) {
        			if(forward_one == 1) {
        				ans[i] = '0';
        			} else {
        				ans[i] = '1';
                    }
        		} else if(dig_a + dig_b == 2) {
        			if(forward_one == 1) 
        				ans[i] = '1';
        			else
        				ans[i] = '0';
        			forward_one = 1;
        		}
        	} else {
        		if(ans[i] == '0') {
        			if(forward_one == 1)
        				ans[i] = '1';
        			forward_one = 0;
        			break;
        		} else if(ans[i] == '1') {
                    if(forward_one == 1) {
        		        ans[i] = '0';
        			    forward_one = 1;
                    } else {
                        ans[i] = '1';
                        forward_one = 0;
                        break;   
                    }
        		}
        	}
        }
        Reverse(ans);

        if(forward_one == 1)
        	return ('1' + ans);
        return ans;
    }
};