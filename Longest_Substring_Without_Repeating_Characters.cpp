class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        if(size == 0 || size == 1)
        	return size;

        int cur_len = 1, max_len = 1, prev_index;
        int visited[256];

        memset(visited, -1, sizeof(visited));

        visited[s[0]] = 0;

        for(int i = 1; i < size; ++i) {
        	prev_index = visited[s[i]];

        	/* If the currentt character is not present in the already processed
            substring or it is not part of the current NRCS, then do cur_len++ */
        	if(prev_index == -1 || i - cur_len > prev_index) {
        		++cur_len;
        	} 
        	/* If the current character is present in currently considered NRCS,
            then update NRCS to start from the next character of previous instance. */
        	else {
        		max_len = (cur_len > max_len ? cur_len : max_len);
        		cur_len = i - prev_index;
        	}

        	visited[s[i]] = i;
        }

        max_len = (cur_len > max_len ? cur_len : max_len);

        return max_len;
    }
};
