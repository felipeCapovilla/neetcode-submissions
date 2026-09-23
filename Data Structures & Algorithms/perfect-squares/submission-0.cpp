class Solution {
public:
    int numSquares(int n) {

        
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

        vector<int> dp(n+1,n);
        dp[0] =0;

        for(int i=1;i<=n;i++){

            for(int k=1; k*k <=i;k++){
                dp[i] = min(dp[i],1+dp[i-k*k]);
            }
        }

        return dp[n];
        
    }
};