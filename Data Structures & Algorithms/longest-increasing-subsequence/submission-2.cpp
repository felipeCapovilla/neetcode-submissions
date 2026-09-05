class Solution {
public:
    int lengthOfLIS(vector<int>& v) {

        int n =v.size();
        if(n < 2){
            return n;
        }

        vector<int> dp(n,1);

        for(int k=1;k<n;k++){
            for(int j=0;j<k;j++){
                if(v[j] < v[k]){
                    dp[k] = max(dp[k],1+dp[j]);
                }
            }
        }

        return *max_element(dp.begin(),dp.end());
        
    }
};
