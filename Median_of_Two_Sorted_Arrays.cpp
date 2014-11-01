class Solution {
public:
    double findMedianSortedArraysRecursion(int A[], int m, int B[], int n, int k) {
        if (m < n)
            return findMedianSortedArraysRecursion(B, n, A, m, k);
        
        if (n == 0)
            return A[k-1];
        if (k == 1)
            return min(A[0], B[0]);
        
        int pb = min(k/2, n);
        int pa = k - pb;
        if (A[pa-1] == B[pb-1])
            return A[pa-1];
        else if (A[pa-1] > B[pb-1])
            return findMedianSortedArraysRecursion(A, m, B+pb, n-pb, k-pb);
        else
            return findMedianSortedArraysRecursion(A+pa, m-pa, B, n, k-pa);
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int sum = m + n;
        if (sum & 0x1) {
            return findMedianSortedArraysRecursion(A, m, B, n, sum/2+1);
        } else {
            return (findMedianSortedArraysRecursion(A, m, B, n, sum/2)
                  + findMedianSortedArraysRecursion(A, m, B, n, sum/2+1)) / 2.0;
        }
    }
};
