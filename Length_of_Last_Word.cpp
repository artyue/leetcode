class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int len = strlen(s);
		if(len == 0)
			return 0;

		const char *p, *q = &(s[len-1]);
		bool flag = false;

		for(; q >= s; q--) {
			if(*q != ' ') {
				flag = true;
				break;
			}
		}
		
		if(flag) {
			for(p = q; p > s; p--) {
				if(*(p-1) == ' ')
					break;
			}
			if(p == (s+1) && *s != ' ')
				p = s;
			return (q - p + 1);
		} else {
			return 0;
		}
	}
};
