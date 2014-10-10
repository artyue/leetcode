class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		int cnt[10];

		for(int i = 0; i < 9; i++) {
			memset(cnt, 0, sizeof(cnt));
			for(int j = 0; j < 9; j++) {
				if(board[i][j] != '.') {
					int num = board[i][j] - '0';
					if(cnt[num] == 0)
						cnt[num]++;
					else if(cnt[num] > 0)
						return false;
				}
			}
		}

		for(int j = 0; j < 9; j++) {
			memset(cnt, 0, sizeof(cnt));
			for(int i = 0; i < 9; i++) {
				if(board[i][j] != '.') {
					int num = board[i][j] - '0';
					if(cnt[num] == 0)
						cnt[num]++;
					else if(cnt[num] > 0)
						return false;
				}
			}
		}

		for(int x = 0; x < 3; x++) {
			for(int y = 0; y < 3; y++) {
				memset(cnt, 0, sizeof(cnt));
				for(int i = 0; i < 3; i++) {
					for(int j = 0; j < 3; j++) {
						if(board[x*3+i][y*3+j] != '.') {
							int num = board[x*3+i][y*3+j] - '0';
							if(cnt[num] == 0)
								cnt[num]++;
							else if(cnt[num] > 0)
								return false;
						}
					}
				}
			}
		}
		
		return true;
	}
};
