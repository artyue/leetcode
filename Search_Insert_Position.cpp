class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		for(int i = 0; i <= n - 1; i++) {
			if(A[i] >= target)
				return i;
			if(i == n - 1)
				return n;
			if(A[i] < target && A[i+1] >= target)
				return (i+1);
		}
	}
};
