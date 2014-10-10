class Solution {
public:
    int sqrt(int x) {
        if(x == 0 || x == 1)
        	return x;

        int s = 1, e = (x/2 < std::sqrt(INT_MAX)) ? (x/2+1) : std::sqrt(INT_MAX); ;
        while(s <= e) {
        	if(s == e)
        		return s;

        	int m = s + (e - s) / 2;
        	if(m * m == x || (m * m < x && (m+1)*(m+1) > x)) {
        		return m;
        	} else if(m * m > x) {
        		e = m - 1;
        	} else {
        		s = m + 1;
        	}
        }

        return s;
    }
};
