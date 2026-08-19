class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(int k=0;k<nums.size();k++){
            if(hash.count(nums[k])){
                return nums[k];
            }
            hash[nums[k]]++;
        }
    }
};
