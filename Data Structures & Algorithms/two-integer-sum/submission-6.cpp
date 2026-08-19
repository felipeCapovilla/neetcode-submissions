

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;

        for(int k=0;k<nums.size();k++){
            if(hash.count(target-nums[k])){
                return {hash[target-nums[k]],k};
            }
            hash[nums[k]]=k;
        }        
    }
};
