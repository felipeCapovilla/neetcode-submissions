class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int target = n-1;
        
        for(int k=n-2; k>=0;k--){
            if(k + nums[k] >= target){
                target = k;
            }

        }

        if(target == 0){
            return true;
        }
        return false;
    }
};
