class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0){
            return 0;
        }else if(n==1){
            return nums[0];
        }
        
        vector<int> dp(n+1);

        
        dp[0]=0;
        dp[1]=nums[0];
        dp[2] = max(nums[0],nums[1]);

        for(int k=3;k<=n;k++){
            dp[k] = max(dp[k-2] + nums[k-1], dp[k-1]);
        }

        return dp[n];

    }
};
