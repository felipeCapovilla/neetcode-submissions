class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        int goal = n-1;

        for(int k=n-2;k>=0;k--){
            if(nums[k] + k >=goal){
                goal=k;
            }
        }

        return goal==0;
        
    }
};
