class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        if(n ==0){
            return 0;
        }
        
        int pre=0;
        int suf=0;
        int res=nums[0];
        
        for(int k=0;k<n;k++){
            pre = nums[k] * (pre==0 ? 1 : pre);
            suf = nums[n-1-k] * (suf==0 ? 1 : suf);

            res = max(res, max(pre,suf));
        }

        return res;

    }
};
