class Solution {
public:
	vector<int> grayCode(int n) {
		int size = 1 << n;
		vector<int> v;
		v.resize(size);
		for(int i = 0; i < size; i++)
			v[i] = (i ^ (i >> 1));
		return v;
    }
};
