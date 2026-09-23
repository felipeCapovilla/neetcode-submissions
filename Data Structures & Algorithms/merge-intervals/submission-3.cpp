class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> output;
        sort(intervals.begin(),intervals.end());
                output.push_back(intervals[0]);

        for(int k=1; k<intervals.size();k++){
            int lastEnd = output.back()[1];
            
            if(intervals[k][0] <= lastEnd){ //Overlap
                output.back()[1] = max(lastEnd,intervals[k][1]);

            }else{
                output.push_back(intervals[k]);
            }
        }

        return output;
        
    }
};
