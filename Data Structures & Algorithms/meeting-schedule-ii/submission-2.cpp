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

        priority_queue<int,vector<int>,greater<int>> heap;

        sort(intervals.begin(),intervals.end(),[](auto& x, auto y){
            return x.start < y.start;
        });

        for(auto interval : intervals){
            if(!heap.empty() && heap.top() <= interval.start){
                heap.pop();
            }
            heap.push(interval.end);
        }


        return heap.size();

    }
};
