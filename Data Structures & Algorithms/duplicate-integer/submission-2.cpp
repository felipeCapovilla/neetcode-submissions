class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map <int,int>hash;

        for(int k=0; k<n;k++){
            if(hash.count(nums[k])){
                return true;
            }
            hash[nums[k]]++;
        }

        return false;


    }
};