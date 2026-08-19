class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int max_global=0;
        unordered_map<int,int> hash;

        for(int k=0;k<nums.size();k++){
            hash[nums[k]]++;
        }

        for(int j=0; j<nums.size();j++){
            if(!hash.count(nums[j]-1)){
                int max_local =0;
                int tmp = nums[j];

                while(hash.count(tmp)){
                    max_local++;
                    tmp++;
                }

                max_global = max(max_global,max_local);
            }
        }

        return max_global;
        
        
    }
};
