class Solution {
public:
    int findMin(vector<int> &nums) {
        int min = nums[0];
        for(int k=0;k<nums.size();k++){
            if(nums[k] < min){
                min = nums[k];
            }
        }

        return min;
        
    }
};
