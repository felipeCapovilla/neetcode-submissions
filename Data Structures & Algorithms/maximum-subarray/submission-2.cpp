class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum =0;
        int max_sum =nums[0];

        for(int k=0; k<nums.size();k++){
            if(sum < 0){
                sum=0;
            }
                sum+=nums[k];
                max_sum = max(max_sum, sum);
            }

        

        return max_sum;

    }
};
