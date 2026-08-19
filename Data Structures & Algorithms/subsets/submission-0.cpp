class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        vector<int> sub;

        dfs(nums,0,sub,out);
        return out;


    }

    void dfs(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& out){
        
        if(i >= nums.size()){ //Caso base.
            out.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums,i+1,subset,out);
        subset.pop_back();
        dfs(nums,i+1,subset,out);
    }
};
