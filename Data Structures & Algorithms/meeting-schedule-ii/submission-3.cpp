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
    int minMeetingRooms(vector<Interval>& intervals) {
        
        int n = intervals.size();
        
        if(n < 2){
            return n;
        }

        priority_queue<int,vector<int>,greater<int>> heap;

        sort(intervals.begin(),intervals.end(),[](const Interval& a, const Interval& b){
            return a.start < b.start;
        });

        for(int k=0; k<n;k++){
            if(!heap.empty() && intervals[k].start >= heap.top()){
                heap.pop();
            }

            heap.push(intervals[k].end);
        }

        return heap.size();



    }
};
