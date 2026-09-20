class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> hash;
        int curr_sum=0;
        int res=0;
        hash[0]++;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            if(hash.count(curr_sum-k)){
                res+=hash[curr_sum-k];
            }
            hash[curr_sum]++;
        }

        return res;
        
    }
};