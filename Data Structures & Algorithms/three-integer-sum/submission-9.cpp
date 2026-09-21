class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> out;
        sort(nums.begin(),nums.end());

        for(int k=0;k<nums.size();k++){
            if(k>0 && nums[k] == nums[k-1]){
                continue;
            }

            int target = -nums[k];
            vector<vector<int>> two = twoSum(k+1,target,nums);
            for(auto par : two){
                par.push_back(nums[k]);
                out.push_back(par);
            }

        }

        return out;
        
    }

    vector<vector<int>> twoSum(int ini, int target, vector<int>& v){

        int l=ini;
        int r=v.size()-1;

        vector<vector<int>> output;

        while(l<r){
            int sum = v[l]+v[r];
            if(sum ==  target){

                output.push_back({v[l],v[r]});

                while(r>l && v[r] == v[r-1]){
                    r--;
                }

                while(r>l && v[l] == v[l+1]){
                    l++;
                }

                l++;
                r--;
            }else if(sum > target){
                r--;
            }else{
                l++;
            }
        }


        return output;
    }
};
