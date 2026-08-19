class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_local, max_global;
        max_local = max_global = nums[0];

        for(int k=1; k<nums.size();k++){
            
            max_local = max(nums[k],max_local + nums[k]);
            if(max_local > max_global){
                max_global = max_local;
            }
        }

        return max_global;

    }
};
