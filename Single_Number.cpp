/*
    Single Number
    算法提示：异或运算具有交换律和结合律。 
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans = 0;
        for(int i = 0;  i < n; i++)
            ans ^= A[i];
        return ans;
    }
};
