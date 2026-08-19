class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m  =nums.size();

        if(m == 0){
            return 0;
        }else if(m == 1){
            return 1;
        }else{

        vector<int> dp(m,1);
        
        for(int n=1;n<m;n++){
            for(int k=0; k<n; k++){
                if(nums[k] <nums[n]){
                    dp[n] = max(dp[n],dp[k] + 1);
                }
            }
        }

        return *max_element(dp.begin(),dp.end());       
        
        }

        
    
    }


};
