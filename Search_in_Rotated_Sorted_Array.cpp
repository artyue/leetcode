class Solution {
public:
    
    int search(int A[], int n, int target) {
        if(n == 0) return -1;
        if(n == 1) {
            if(A[0] == target)
                return 0;
            else
                return -1;
        }
        
        int i = 0, j = n - 1;
        
        while(i <= j) {
            if(i == j) {
                if(A[i] == target)
                    return i;
                return -1;
            }
            if(j - i == 1) {
                if(A[i] == target)
                    return i;
                if(A[j] == target)
                    return j;
                return -1;
            }
            int mid = i + (j - i) / 2;
            if(A[mid] == target)
                return mid;
            if(A[mid] > target) {                    // 接下去需判断mid和target是否落在同一单调区间内
                if(target >= A[i] || A[mid] <= A[j]) // 在同一单调区间内
                    j = mid - 1;
                else                                 // 不在同一单调区间内
                    i = mid + 1;
            }
            if(A[mid] < target) {                    // 接下去需判断mid和target是否落在同一单调区间内
                if(A[mid] >= A[i] || target <= A[j]) // 在同一单调区间内
                    i = mid + 1;
                else                                 // 不在同一单调区间内
                    j = mid - 1;
            }
        }
        return -1;
    }
};
