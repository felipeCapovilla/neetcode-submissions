class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        int n = nums.size();

        if(n < 3){
            return {};
        }

        sort(nums.begin(),nums.end());
        
        for(int k=0; k<n-2;k++){
            if(k >0 && nums[k] == nums[k-1]){
                continue;
            }

            int ini = k+1;
            int fim = n-1;
            int target = -nums[k];

            while(ini < fim){
                int sum = nums[ini] + nums[fim];
                if(sum == target){
                    output.push_back({nums[k],nums[ini],nums[fim]});
                
                
                    while(ini < fim && nums[ini] == nums[ini+1]){
                        ini++;
                    }
                    while(ini < fim && nums[fim] ==nums[fim-1]){
                        fim--;
                    }

                    ini++;
                    fim--;
                }else if(sum > target){
                    fim--;
                }else{
                    ini++;
                }


            }
        }

        return output;
        
    }
};
