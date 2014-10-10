class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> bounds;
        bounds.push_back(-1);
        bounds.push_back(-1);

        if(n == 1) {
            if(A[0] == target)
                bounds[0] = bounds[1] = 0;
            return bounds;
        }
        
        /* find the lower bound */
        int i = 0, j = n - 1;
        while(i < j) {
          	int mid = i + (j - i) / 2;
        	if(A[mid] > target)
        		j = mid;
        	else if(A[mid] < target)
        		i = mid + 1;
        	else if(A[mid] == target)
        		j = mid;
        }
        if(A[i] == target)
        	bounds[0] = i;
        else
        	return bounds;

        /* find the upper bound */
        i = bounds[0], j = n; /* BE CAREFUL: j is assigned n here. */
        while(i < j) {
        	int mid = i + (j - i) / 2;
        	if(A[mid] < target)
        		i = mid + 1;
        	else if(A[mid] > target)
        		j = mid;
        	else if(A[mid] == target)
        		i = mid + 1;
        }
        bounds[1] = i-1;

        return bounds;
    }
};