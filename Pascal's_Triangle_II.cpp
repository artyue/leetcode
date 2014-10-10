class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex + 1;
        if(numRows == 0) {
			vector<vector<int> > v(0);
			return v[rowIndex];
		}
		if(numRows == 1) {
			vector<vector<int> > v(1);
			v[0].push_back(1);
			return v[rowIndex];
		}
		if(numRows == 2) {
			vector<vector<int> > v(2);
			v[0].push_back(1);
			v[1].push_back(1);
			v[1].push_back(1);
			return v[rowIndex];
		}
		if(numRows >= 3) {
			vector<vector<int> > v(numRows);
			v[0].push_back(1);
			v[1].push_back(1);
			v[1].push_back(1);
			for(int i = 2; i <= numRows-1; i++)
				for(int j = 0; j <= i; j++)
					if(j == 0 || j == i)
						v[i].push_back(1);
					else 
						v[i].push_back(v[i-1][j-1] + v[i-1][j]);
			return v[rowIndex];
		}
    }
};
