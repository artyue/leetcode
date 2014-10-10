class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		if(n == 0)
			return 0;

		int f = -1, r;
		sort(A, A+n);
		
		for(int i = 0; i < n; i++) {
			if(A[i] == elem) {
				f = i;
				for(int j = f; j < n; j++) {
					if(A[j] == elem)
						r = j;
					else
						break;
				}
				break;
			}
		}

		if(f != -1) {
			int len = r - f + 1;
			if(r < n-1) {
				for(int i = r+1; i < n; i++)
					A[i-len] = A[i];
			}
			return (n-len);
		} else {
			return n;
		}
	}
};
