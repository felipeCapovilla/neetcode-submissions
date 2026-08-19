class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int,int> hash;
        int n = nums.size();

        for(int k=0; k<n; k++){
            hash[nums[k]]++;
        }

        int tam =1;
        int maxTam=0;

        for(auto& par : hash){
            tam = 0;
            if(!hash.count(par.first - 1)){ //Cabeca de chave.
                int ini = par.first;
                while(hash.count(ini)){
                    tam+=1;
                    ini+=1;
                }
            maxTam = max(tam,maxTam);
            }else{
                continue;
            }
        }

        return maxTam;


        
    }
};