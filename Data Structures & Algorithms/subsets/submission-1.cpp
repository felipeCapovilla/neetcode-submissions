class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path = {};
        vector<vector<int>> output = {};

        dfs(nums,path,output,0);
        return output;

    }

    void dfs(vector<int>&nums, vector<int>& path, vector<vector<int>>& out, int i){
        if(i >= nums.size()){
            out.push_back(path);
            return;
        }


        path.push_back(nums[i]);
        dfs(nums,path,out,i+1);
        path.pop_back();
        dfs(nums,path,out,i+1);

    }
};
