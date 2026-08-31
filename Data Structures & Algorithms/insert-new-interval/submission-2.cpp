class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> out;

        for(int k=0;k <intervals.size();k++){
            if(newInterval[1] < intervals[k][0]){
                out.push_back(newInterval);

                for(int i=k; i<intervals.size();i++){
                    out.push_back(intervals[i]);
                }

                return out;

            }else if(newInterval[0] > intervals[k][1]){
                out.push_back(intervals[k]); //Ainda podemos ter overlap com os futuros intervalos.
            }else{
                newInterval = {min(newInterval[0], intervals[k][0]), max(newInterval[1], intervals[k][1])};

            }
        }

            out.push_back(newInterval);
            return out;

    }
};
