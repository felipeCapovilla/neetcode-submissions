class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1);

        dp[0]=0;
        dp[1]=0;

        for(int k=2;k<=n;k++){
            dp[k] = min(dp[k-1] + cost[k-1], dp[k-2] + cost[k-2]);
        }

        return dp[n];
        
    }
};
