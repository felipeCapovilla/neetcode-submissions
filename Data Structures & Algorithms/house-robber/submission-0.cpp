class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        vector<int>tab(n,0);
        
        tab[0] = nums[0];
        tab[1]= max(nums[0],nums[1]);

        for(int k=2;k<n;k++){
            tab[k] = max(tab[k-1],tab[k-2]+nums[k]);
        }

        return tab[n-1];
        
    }
};
