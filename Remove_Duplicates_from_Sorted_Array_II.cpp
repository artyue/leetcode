class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0 || n == 1)
            return n;
        
        int i = 2, j;
        for(; i <= n-1; i++) {
            if(A[i] == A[i-2]) {
                if(A[n-1] == A[i])
                    return i;
                for(j = i+1; j <= n-1; j++) {
                    if(A[j] != A[i])
                        break;    
                }
                for(int k = j; k <= n-1; k++) {
                    A[k-(j-i)] = A[k];
                }
                n = n-(j-i);
            }
        }
        return n;
    }
};
