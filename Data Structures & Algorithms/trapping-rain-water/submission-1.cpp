class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<vector<int>> dp(3,vector<int>(n,0));

        int maxL=0;
        for(int k=0;k<n;k++){
            dp[0][k] = maxL;
            maxL = max(maxL,height[k]);
        }

        int maxR=0;
        for(int k=n-1;k>=0;k--){
            dp[1][k] = maxR;
            maxR = max(maxR,height[k]);
        }

        for(int k=0;k<n;k++){
            dp[2][k] = min(dp[1][k],dp[0][k]);
        }

        int cont=0;

        for(int k=0;k<n;k++){
            cont+=max(0,dp[2][k] - height[k]);
        }

        return cont;
        
    }
};
