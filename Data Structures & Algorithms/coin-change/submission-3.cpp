class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }

        int max_val = amount+1;
        vector<int> dp(amount+1,max_val);
        dp[0]=0;

        for(int k=1;k<=amount;k++){
            for(int c=0;c<coins.size();c++){
                if(coins[c] <= k){

                dp[k] = min(dp[k],1+dp[k-coins[c]]);
                }

            }
        }

        return dp[amount] == max_val ? -1 : dp[amount];
        
    }
};
