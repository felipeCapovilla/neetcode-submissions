class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int,int> hash;

        for(int num : nums){
            hash[num]++;
        }

        int tam =0;
        for(auto par : hash){
            if(hash.count(par.first-1)){
                continue;
            }else{
                int element = par.first;
                int curr_tam=0;
                while(hash.count(element)){
                    curr_tam++;
                    element++;
                }

                tam = max(tam,curr_tam);
            }
        }

        return tam;
        
    }
};
