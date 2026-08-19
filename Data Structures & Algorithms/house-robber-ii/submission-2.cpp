class Solution {
public:
    int rob(vector<int>& nums) {   
    
    int r1,r2;
    int n = nums.size();

    if(n == 1){
        return nums[0];
    }

    r1 = robTest(0,n-2,nums);
    r2 = robTest(1,n-1,nums);

    return max(r1,r2);    
    }


    int robTest(int ini, int fim, vector<int>& v){
        vector<int> dp(fim-ini+1);

        if(ini == fim){
            return v[ini];
        }

        dp[0] = v[ini];
        dp[1] = max(v[ini],v[ini+1]);
        
        for(int n=2; n<fim-ini+1;n++){
            dp[n] = max(dp[n-1],dp[n-2] + v[ini+n]);
        }

        return dp[fim-ini];

    }
};
