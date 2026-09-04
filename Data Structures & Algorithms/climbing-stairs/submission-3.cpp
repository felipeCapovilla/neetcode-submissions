class Solution {
public:
    int climbStairs(int n) {
        
        if(n < 3){
            return n;
        }
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;

        for(int k=3;k<=n;k++){
            dp[k] = dp[k-1]+dp[k-2];
        }

        return dp[n];
        
    }
};
