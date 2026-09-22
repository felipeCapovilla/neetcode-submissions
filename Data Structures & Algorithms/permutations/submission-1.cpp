class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
        vector<bool>used(n,false);
        vector<int> path;
        vector<vector<int>> output;

        dfs(output,nums,used,path);
        return output;

        
    }


    void dfs(vector<vector<int>>& output, vector<int>& nums, vector<bool>& used, vector<int>& path){
        if(path.size() == nums.size()){
            output.push_back(path);
            return;
        }

        for(int k=0;k<nums.size();k++){
            if(!used[k]){
                path.push_back(nums[k]);
                used[k]=true;
                dfs(output,nums,used,path);
                path.pop_back();
                used[k]=false;
            }else{
                continue;
            }
        }

        
        
    }
};
