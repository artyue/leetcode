/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(const Interval &a, const Interval &b) {
    if (a.start != b.start)
        return (a.start < b.start);
    else
        return (a.end < b.end);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> v;
        int size = intervals.size();
        if(size == 0)
            return v;
        sort(intervals.begin(), intervals.end(), cmp);
        int cur_s = intervals[0].start, cur_e = intervals[0].end;
        for (vector<Interval>::iterator iter = (intervals.begin() + 1); 
                                        iter != intervals.end(); 
                                        ++iter) {
            if (iter->start <= cur_e) {
                if (cur_e < iter->end) {
                    cur_e = iter->end;
                }
            } else {
                v.push_back(*(new Interval(cur_s, cur_e)));
                cur_s = iter->start;
                cur_e = iter->end;
            }
        }
        v.push_back(*(new Interval(cur_s, cur_e)));
        return v;
    }
};
