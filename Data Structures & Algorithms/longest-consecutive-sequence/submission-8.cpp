class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(int k=0; k<nums.size();k++){
            
            if(hash.count(nums[k])){
                continue;
            }else{
                hash[nums[k]]++;
            }
            
        }


        int maxSize =0;

        for(int i=0;i<nums.size();i++){
            int cont=0;

            if(!hash.count(nums[i]-1)){
                int k =nums[i];

                while(hash.count(k)){
                    cont++;
                    k+=1;
                }

                maxSize = max(maxSize,cont);
            }
        }


        return maxSize;


        
    }
};
