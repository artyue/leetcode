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
            if(A[mid] > target) {                    // ����ȥ���ж�mid��target�Ƿ�����ͬһ����������
                if(target > A[i] || A[mid] < A[j])   // ��ͬһ����������
                    j = mid - 1;
                else if(target == A[i])              // ����ͬһ����������
                    return true;
                else if(A[mid] == A[j])
                    j--;
                else
                    i = mid + 1;
            }
            if(A[mid] < target) {                    // ����ȥ���ж�mid��target�Ƿ�����ͬһ����������
                if(A[mid] > A[i] || target < A[j])   // ��ͬһ����������
                    i = mid + 1;
                else if(A[mid] == A[i])              // ����ͬһ����������
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
