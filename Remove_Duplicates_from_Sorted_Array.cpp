class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if(n == 0)
			return 0;
		int b[n];
		int cnt = 1;
		b[0] = A[0];

		for(int i = 1; i < n; i++) {
			if(A[i] != b[cnt-1]) {
				b[cnt] = A[i];
				cnt++;
			}
		}
		
		for(int i = 0; i < cnt; i++)
			A[i] = b[i];

		return cnt;
    }
};
