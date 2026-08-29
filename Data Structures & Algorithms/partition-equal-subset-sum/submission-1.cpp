class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum=0;
        for(int k=0;k<nums.size();k++){
            sum+=nums[k];
        }

        if(sum % 2== 1){
            return false;
        }

        int n = nums.size();
        int target = sum/2;

        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }

        for(int j=0;j<=target;j++){
            dp[0][j] = false;
        }
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i] < j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];               
                }
                
            }
        }

        return dp[n-1][target];
    }
};
