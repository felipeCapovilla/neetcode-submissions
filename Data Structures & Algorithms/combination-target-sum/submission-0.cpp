class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> output = {};
        vector<int> curr = {};

        dfs(nums,target,output,curr,0);
        return output;


    }

    void dfs(vector<int>&nums, int target, vector<vector<int>>& out, vector<int>& path, int ini){
        if(target ==0){
            out.push_back(path);
            return;
        }

        for(int k=ini; k<nums.size();k++){
            if(nums[k] <= target){
                path.push_back(nums[k]);
                dfs(nums,target-nums[k],out,path,k);
                path.pop_back();
            }
        }
    }
};
