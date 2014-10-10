class Solution {
public:
	double powRecursive(double x, int exp) {
		if(exp == 0)
			return 1;

		double cur = powRecursive(x, exp/2);
		if(exp & 0x1)
			return (x * cur * cur);
		else
			return (cur * cur);
	}

    double pow(double x, int n) {
        if(n == 0)
        	return 1;
        if(n == 1)
        	return x;

        if(n > 0)
        	return powRecursive(x, n);
        else
        	return 1.0/powRecursive(x, abs(n));
    }
};