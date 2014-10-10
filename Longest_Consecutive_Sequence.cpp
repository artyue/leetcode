class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		int size = num.size();
		if(size == 0) return 0;
		if(size == 1) return 1;

		unordered_map<int, int> hash_cnt;
		int MAX_LEN = 1;

		for(int i = 0; i < size; i++)
			hash_cnt[num[i]] = 0;

		int up, down;
		for(int i = 0; i < size; i++) {
		    if(hash_cnt[num[i]] != 0)
                continue;
			up = num[i] + 1;
			down = num[i] - 1;
			if(!hash_cnt.count(up) && !hash_cnt.count(down) ) {
                hash_cnt[num[i]] = 1;
			} else if(!hash_cnt.count(up) && hash_cnt.count(down)) {
				if(hash_cnt[down] != 0) {
                    hash_cnt[num[i]] = hash_cnt[down] + 1;
				    hash_cnt[num[i] - hash_cnt[down]] = hash_cnt[num[i]]; 
                } else {
                    hash_cnt[num[i]] = 1;
                }
			} else if(hash_cnt.count(up) && !hash_cnt.count(down) ) {
                if(hash_cnt[up] != 0) {
				    hash_cnt[num[i]] = hash_cnt[up] + 1;
				    hash_cnt[num[i] + hash_cnt[up]] = hash_cnt[num[i]];
                } else {
                    hash_cnt[num[i]] = 1;  
                }
			} else if(hash_cnt.count(up)  && hash_cnt.count(down)) {
				if(hash_cnt[up] == 0 && hash_cnt[down] == 0) {
                    hash_cnt[num[i]] = 1; 
                } else if(hash_cnt[up] != 0 && hash_cnt[down] == 0) {
                    hash_cnt[num[i]] = hash_cnt[up] + 1;
				    hash_cnt[num[i] + hash_cnt[up]] = hash_cnt[num[i]];
                } else if(hash_cnt[up] == 0 && hash_cnt[down] != 0) {
                    hash_cnt[num[i]] = hash_cnt[down] + 1;
				    hash_cnt[num[i] - hash_cnt[down]] = hash_cnt[num[i]];  
                } else if(hash_cnt[up] != 0 && hash_cnt[down] != 0) {
                    hash_cnt[num[i]] = hash_cnt[up] + hash_cnt[down] + 1;
				    hash_cnt[num[i] - hash_cnt[down]] = hash_cnt[num[i] + hash_cnt[up]] = hash_cnt[num[i]];
                }
			}
			MAX_LEN = (MAX_LEN < hash_cnt[num[i]] ? hash_cnt[num[i]] : MAX_LEN);
		}
		
		return MAX_LEN;
	}
};
