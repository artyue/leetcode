class Solution {
public:
	void sortColors(int A[], int n) {
		/*
		 * The elements before p1 are all ZERO,
		 * the elements after p2 are all TWO,
		 * the elements between p1 and p2 (including p1 and p2) are the elements, which are not checked.
		 * */
		int p, p1 = 0, p2 = n-1;

		for(p = 0; p <= p2;) {
			if(A[p] == 0) {
				A[p] = A[p1];
				A[p1] = 0;
				p1++;
				p++;
			} else if(A[p] == 2) {
				A[p] = A[p2];
				A[p2] = 2;
				p2--;
			} else {
				p++;
			}
		}
	}
};
