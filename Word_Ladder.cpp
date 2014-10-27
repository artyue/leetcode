class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, int> table;
        queue<string> q;
        table[start] = 1;
        
        q.push(start);
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            for (int i = 0; i < cur.size(); ++i) {
                string cur_next = cur;
                for (int j = 0; j < 26; ++j) {
                    cur_next[i] = 'a' + j;
                    if (cur_next == end)
                        return (table[cur] + 1);
                    if (cur_next != cur && dict.find(cur_next) != dict.end() && table.find(cur_next) == table.end()) {
                        table[cur_next] = table[cur] + 1;
                        q.push(cur_next);
                        
                    }
                }
            }
        }
        
        if (table.find(end) == table.end())
            return 0;
        return table[end];
    }
};
