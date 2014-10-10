class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> v;
        int size = strs.size();
        if(size == 0)
        	return v;

        map<string, int> mp;

        for(int i = 0; i < size; ++i) {
        	string s = strs[i];
        	sort(s.begin(), s.end());
        	if(mp.find(s) == mp.end()) {
        		mp[s] = i;
        	} else {
        		if(mp[s] >= 0) {
        			v.push_back(strs[mp[s]]);
        			mp[s] = -1;
        		}
        		v.push_back(strs[i]);
        	}
        }

        return v;
    }
};