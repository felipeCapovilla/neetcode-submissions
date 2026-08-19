class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        
        vector<int> maxDp(n);
        vector<int> minDp(n);
        maxDp[0] = nums[0];
        minDp[0] = nums[0];

        for(int k=1; k<n;k++){
            maxDp[k] = max(max(nums[k],nums[k]*maxDp[k-1]),nums[k]*minDp[k-1]);
            minDp[k] = min(min(nums[k],nums[k]*maxDp[k-1]),nums[k]*minDp[k-1]);
        }

        return *max_element(maxDp.begin(),maxDp.end());


        
    }
};
