class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        set<vector<int>> output = {};
        vector<int> path;
        sort(nums.begin(),nums.end());

        dfs(nums,path,output,0);

        return vector<vector<int>>(output.begin(),output.end());
        
    }

    void dfs(vector<int>& nums, vector<int>& path, set<vector<int>>& out, int i){
        
        if(i == nums.size()){

                out.insert(path);

             
            return;
        }

        path.push_back(nums[i]);
        dfs(nums,path,out,i+1);
        path.pop_back();
        dfs(nums,path,out,i+1);


    }
};
