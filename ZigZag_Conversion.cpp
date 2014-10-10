class Solution {
public:
    string convert(string s, int nRows) {
    	int size = s.size();
        if(size == 0 || nRows == 1)
        	return s;

        string ans = s;
        int nCols = (size + size % 2)  * (nRows - 1) / (2 * nRows - 2);
        
        int arr[nRows][nCols];
        memset(arr, -1, sizeof(arr));

        int cur_x = 0, cur_y = 0;
        int del_x, del_y;
        for(int i = 0; i < size; ++i) {
        	arr[cur_x][cur_y] = i;
        	if(cur_x == 0) {
        	    del_x = 1;
        	    del_y = 0;
        	} else if(cur_x == nRows - 1) {
                del_x = -1;
        	    del_y = 1;
            }
            cur_x += del_x;
            cur_y += del_y;
        }

        int ct = 0;
        for(int i = 0; i < nRows; ++i) {
        	for(int j = 0; j < nCols; ++j) {
        		if(arr[i][j] != -1) {
        			ans[ct] = s[arr[i][j]];
        			++ct;
        		}
        	}
        }

        return ans;
    }
};