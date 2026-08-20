class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }

        sort(nums.begin(),nums.end());
        set<vector<int>> uniqueTriplets;
        for(int k=0; k<n-1;k++){
            twoSum(k+1,uniqueTriplets,-nums[k],nums);
        }

        return vector<vector<int>>(uniqueTriplets.begin(),uniqueTriplets.end());
        
    }
    

    void twoSum(int start, set<vector<int>>& trips, int target, vector<int>& v){
        int ini,fim,sum;
        ini =start;
        fim = v.size()-1;

        while(ini < fim){
            sum = v[ini] + v[fim];
            if(sum == target){
                trips.insert({-target, v[ini],v[fim]});
                ini++;
                fim--;
            }else if(sum > target){
                fim--;
            }else{
                ini++;
            }
        }
    }
};
