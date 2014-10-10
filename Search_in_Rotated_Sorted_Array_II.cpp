class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n == 0) return -1;
        if(n == 1) {
            if(A[0] == target)
                return true;
            else
                return false;
        }
        
        int i = 0, j = n - 1;
        
        while(i <= j) {
            if(i == j) {
                if(A[i] == target)
                    return true;
                return false;
            }
            if(j - i == 1) {
                if(A[i] == target)
                    return true;
                if(A[j] == target)
                    return true;
                return false;
            }
            int mid = i + (j - i) / 2;
            if(A[mid] == target)
                return true;
            if(A[mid] > target) {                    // 接下去需判断mid和target是否落在同一单调区间内
                if(target > A[i] || A[mid] < A[j])   // 在同一单调区间内
                    j = mid - 1;
                else if(target == A[i])              // 不在同一单调区间内
                    return true;
                else if(A[mid] == A[j])
                    j--;
                else
                    i = mid + 1;
            }
            if(A[mid] < target) {                    // 接下去需判断mid和target是否落在同一单调区间内
                if(A[mid] > A[i] || target < A[j])   // 在同一单调区间内
                    i = mid + 1;
                else if(A[mid] == A[i])              // 不在同一单调区间内
                    i++;
                else if(target == A[j])
                    return true;
                else
                    j = mid - 1;
            }
        }
        return false;
    }
};
