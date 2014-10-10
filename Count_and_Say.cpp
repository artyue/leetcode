class Solution {
public:
    string countAndSay(int n) {
        if(n == 0)
        	return "";

        string ans = "1";
        
        while(--n > 0) {
        	char buf[10];
 		    int cnt = 1; // count for ans[0]
 		    string tmp_ans = "";
 		    for(int i = 1; i < ans.size(); i++) {
 		    	if(ans[i] == ans[i-1]) {
 		    		cnt++;
 		    	} else {
					sprintf(buf, "%d", cnt);
					tmp_ans += buf;
 		    		tmp_ans += ans[i-1];
 		    		cnt = 1;
 		    	}
 		    }
			sprintf(buf, "%d", cnt);
			tmp_ans += buf;
			tmp_ans += ans[ans.size()-1];

 		    ans = tmp_ans;
        }
        return ans;
    }
};