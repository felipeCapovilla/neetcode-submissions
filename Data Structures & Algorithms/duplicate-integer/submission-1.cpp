class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;

        for(int k=0;k<nums.size();k++){
            hash[nums[k]]+=1;
        }

        for(auto it = hash.begin(); it!= hash.end(); ++it){
            if(hash[it->first] > 1){
                return true;
            }
        }

        return false;


        
    }
};