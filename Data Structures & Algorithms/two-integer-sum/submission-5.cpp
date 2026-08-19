class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> hash;
        
        for(int k=0; k<nums.size();k++){
            int diff = target - nums[k];
           
            if(hash.count(diff)){
                return {hash[diff],k};
            }
            hash[nums[k]]=k;
        }

    }
};
