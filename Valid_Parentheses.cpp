class Solution {
public:
	bool isValid(string s) {
		int cnt[6] = {0, 0, 0, 0, 0, 0};
		stack<char> sk;

		for(int i = 0; i < s.size(); i++) {
			switch(s[i]) {
				case '(':
					cnt[0]++;
					sk.push(s[i]);
					break;
				case ')':
					if(sk.empty() || sk.top() != '(')
						return false;
					else 
						sk.pop();
					cnt[1]++;
					break;
				case '{':
					cnt[2]++;
					sk.push(s[i]);
					break;
				case '}':
					if(sk.empty() || sk.top() != '{')
						return false;
					else
						sk.pop();
					cnt[3]++;
					break;
				case '[':
					cnt[4]++;
					sk.push(s[i]);
					break;
				case ']':
					if(sk.empty() || sk.top() != '[')
						return false;
					else
						sk.pop();
					cnt[5]++;
					break;
			}
			if(cnt[1] > cnt[0])
				return false;
			if(cnt[3] > cnt[2])
				return false;
			if(cnt[5] > cnt[4])
				return false;
		}
		if(cnt[0] != cnt[1] || cnt[2] != cnt[3] || cnt[4] != cnt[5])
			return false;
		return true;
	}
};
