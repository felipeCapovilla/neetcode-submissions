class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int>v(nums.size(),0);
        vector<int> path;

        dfs(nums,path,v,out);
        return out;
    }


    void dfs(vector<int>& nums, vector<int>& path, vector<int>& v, vector<vector<int>>& out){


        if(path.size() == nums.size()){ //Caso base.
            out.push_back(path);
            return;
        }

        for(int k=0; k<nums.size();k++){
            if(v[k] == 1){
                continue;
            }

            v[k] =1;
            path.push_back(nums[k]);
            dfs(nums,path,v,out);
            path.pop_back();
            v[k]=0;
        }

    }
};
