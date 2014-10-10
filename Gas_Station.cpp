class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int size = gas.size();
        if(size == 1) {
            if(gas[0] >= cost[0])
                return 0;
            else
                return -1;
        }

        int start = 0, remain = 0;
        for(int i = 0; i < size * 2; ++i) {
        	if((i >= size) && (i % size == start))
        		return start;

        	if(remain + gas[i%size] >= cost[i%size]) {
        		remain = remain + gas[i%size] - cost[i%size];
        	} else {
        		if(i >= size)
        			return -1;
        		start = (i + 1) % size;
        		remain = 0;
        	}
        }

        return -1;
    }
};