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

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        int n = intervals.size();
        if(n < 2){
            return true;
        }

        sort(intervals.begin(),intervals.end(),[](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        for(int k=0; k<n-1;k++){
            if(intervals[k+1].start < intervals[k].end){
                return false;
            }

        }

        return true;

        
    }
};
