class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }

        sort(nums.begin(),nums.end());
        int max_global,max_local;
        max_global=1;

        max_local=1;
        for(int k=1;k<nums.size();k++){
            
            if(nums[k] == nums[k-1]){
                continue;
            }
            
            if(nums[k] == nums[k-1] +1){
                max_local++;
            }else{
                max_local=1;
            }
            max_global = max(max_local,max_global);
        }


        return max_global;
        
    }
};
