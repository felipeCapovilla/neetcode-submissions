class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = amount;
        vector<int>dp(n+1,n+1);
        
        dp[0] = 0;
        
        for(int k=1; k<=n;k++){

            for(int c=0; c<coins.size(); c++){
                if(k >= coins[c]){
                    dp[k] = min(dp[k],1+dp[k-coins[c]]);
                }
                
            }
            
        }
        if(dp[n] != n+1){
            return dp[n];
        }return -1;
        
    }
};