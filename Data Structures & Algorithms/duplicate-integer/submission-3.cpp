class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        if(nums.size() < 2){
            return false;
        }

        unordered_map<int,int> hash;
        
        for(int k=0; k<nums.size();k++){
            if(hash.count(nums[k])){
                return true;
            }
            hash[nums[k]]++;
        }

        return false;

    }
};