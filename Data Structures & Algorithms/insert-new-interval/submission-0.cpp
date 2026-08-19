class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for(int k=0; k<intervals.size();k++){
            if(newInterval[1] < intervals[k][0]){
                res.push_back(newInterval);
                for(int i=k;i<intervals.size();i++){
                    res.push_back(intervals[i]);

                }
                return res;
            }else if(newInterval[0] > intervals[k][1]){
                res.push_back(intervals[k]);

            }else{
                newInterval = {min(newInterval[0],intervals[k][0]), max(newInterval[1],intervals[k][1])};
            }
        }
                            res.push_back(newInterval);
            return res;

        
    }
};
