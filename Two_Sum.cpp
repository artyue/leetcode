class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> v;
        size_t size = numbers.size();
        if (size <= 1)
            return v;
        
        map<int, int> mp;
        for (int i = 0; i < size; ++i) {
            if (mp.find(target - numbers[i]) != mp.end()) {
                v.push_back(mp[target-numbers[i]]+1);
                v.push_back(i+1);
                return v;
            } else {
                mp[numbers[i]] = i;
            }
        }
        return v;
    }
};
