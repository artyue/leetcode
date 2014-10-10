class Solution {
public:
	bool canJump(int A[], int n) {
		if(n == 0)	return true;

		if(A[0] >= n-1) return true;
	
		int reach[n];
		memset(reach, 0, sizeof(reach));
		
		for(int i = n-2; i >= 0; i--) {
			if(i + A[i] >= n - 1)
				reach[i] = 1;
			else
				reach[i] = reach[i + A[i]];
		}
		return reach[0];
	}
};
