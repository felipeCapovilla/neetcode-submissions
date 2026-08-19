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
        
        unordered_map<int,int> hash;
        for(auto par : intervals){
            
            int start,end;
            start = par.start;
            end = par.end;

            for(int i=start;i<=end;i++){
                if(hash.count(i) && hash.count(i+1)){
                    return false;
                }
                hash[i]++;
            }

        }

        return true;

        
    }
};
