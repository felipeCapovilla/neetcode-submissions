class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> path = {};

        sort(nums.begin(),nums.end());
        dfs(0,path,output,nums);
        return output;
        
    }


    void dfs(int i, vector<int>& path, vector<vector<int>>& out, vector<int>& nums){

        out.push_back(path);


        for(int k=i;k<nums.size();k++){
            if(k > i && nums[k] == nums[k-1]){
                continue;
            }

            path.push_back(nums[k]);
            dfs(k+1,path,out,nums);
            path.pop_back();
        }

        }

};
