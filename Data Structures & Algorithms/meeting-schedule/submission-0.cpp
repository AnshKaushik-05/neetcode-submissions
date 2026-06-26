/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class cmp{
public:
    bool operator()(Interval a,Interval b){
        if(a.start<b.start) return true;
        return false;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp());
        int n=intervals.size();
        for(int i=0;i<n-1;i++){
            if(intervals[i].end>intervals[i+1].start) return false;
        }
        return true;
    }
};
