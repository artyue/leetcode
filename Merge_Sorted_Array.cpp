class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		if((!m && !n) || (m && !n))
			return;
		if(!m && n) {
			for(int i = 0; i < n; i++)
				A[i] = B[i];
			return;
		}

		int C[m+n];
		int ca = 0, cb = 0;
		for(int i = 0; i < m + n; i++) {
			if(ca < m && cb < n) {
				if(A[ca] < B[cb])
					C[i] = A[ca++];
				else
					C[i] = B[cb++];
			} else if(ca == m && cb < n) {
				for(int j = i; j < m + n; j++)
					C[j] = B[cb+(j-i)];
				break;
			} else if(ca < m && cb == n) {
				for(int j = i; j < m + n; j++)
					C[j] = A[ca+(j-i)];
				break;
			} else if(ca == m && cb == n) {
				break;
			}
		}
		for(int i = 0; i < m + n; i++)
			A[i] = C[i];
    }
};
