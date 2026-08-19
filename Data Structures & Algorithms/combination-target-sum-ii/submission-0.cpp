class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> output;
        vector<int> path = {};
        sort(candidates.begin(),candidates.end());
        dfs(candidates,path,output,0,target);
        return output;
        
    }

    void dfs(vector<int>& nums, vector<int>& path,vector<vector<int>>& out, int ini, int target){
        if(target == 0){
            out.push_back(path);
            return;
        }


        for(int k=ini;k<nums.size();k++){

            if(k>ini && nums[k] == nums[k-1]){
                continue;
            }
            if(nums[k] <= target){
                path.push_back(nums[k]);
                dfs(nums,path,out,k+1,target-nums[k]);
                path.pop_back();
            }
        }
    }



};
