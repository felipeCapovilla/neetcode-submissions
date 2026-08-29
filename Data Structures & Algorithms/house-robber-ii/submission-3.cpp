class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0){
            return 0;
        }else if(n==1){
            return nums[0];
        }


        int r1 = roubar(nums,0,n-1);
        int r2 = roubar(nums,1,n);

        return max(r1,r2);
        
    }

    int roubar(vector<int>& nums, int ini, int fim){
        int n = fim-ini;
        vector<int>dp(n+1);

        dp[0] =0;
        dp[1] = nums[ini];

        for(int k=2;k<=n;k++){
            dp[k] = max(nums[ini+k-1] + dp[k-2],dp[k-1]);
        }

        return dp[n];

    }
};
