class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hash;
        vector<int> out;
        for(int k=0; k<nums.size();k++){
            hash[nums[k]]=k;
        }

        for(int k=0; k<nums.size();k++){
            int value = target - nums[k];
            if(hash.count(value) && hash[value] != k){
                out = {k,hash[value]};
                return out;
            }
        }
        

        return {};
        
    }
};
