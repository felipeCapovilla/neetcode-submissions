class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        if(n < 2){
            return intervals;
        }

        vector<vector<int>> output;

        sort(intervals.begin(),intervals.end());
        for(int k=0; k<n-1;k++){
            if(intervals[k][1] < intervals[k+1][0]){
                output.push_back(intervals[k]);
            }else{
                intervals[k+1] = {min(intervals[k][0],intervals[k+1][0]), max(intervals[k][1], intervals[k+1][1])};
            }
        }

        output.push_back(intervals[n-1]);
        return output;  
    }
};
