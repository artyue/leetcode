class Solution {
public:

	inline int getMin(int a, int b) {
		return ((a > b) ? b : a);
	}

	int trap(int A[], int n) {
		if(n == 0 || n == 1 || n == 2)
			return 0;

		int leftHeight[n], rightHeight[n];

		leftHeight[0] = A[0];
		for(int i = 1; i <= n-1; i++)
			leftHeight[i] = (A[i] < leftHeight[i-1] ? leftHeight[i-1] : A[i]);
		
		rightHeight[n-1] = A[n-1];
		for(int i = n-2; i >= 0; i--)
			rightHeight[i] = (A[i] < rightHeight[i+1] ? rightHeight[i+1] : A[i]);
		
		int water = 0;
		for(int i = 1; i <= n - 2; i++) 
			water += (getMin(leftHeight[i], rightHeight[i]) - A[i]);
		
		return water;
	}
};
