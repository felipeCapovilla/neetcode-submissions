class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;

        for(int i=0;i<nums.size();i++){
            if(!hash.count(nums[i])){
                hash[nums[i]]=i;
            }else{
                if(abs(i - hash[nums[i]]) > k){
                    hash[nums[i]]=i;
                }else{
                    return true;
                }
            }
        }

        return false;
        
    }
};