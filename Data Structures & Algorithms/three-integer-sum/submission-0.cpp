class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> startHash;
        vector<vector<int>> res;

        for(int k=0; k<nums.size();k++){
            if(startHash.find(nums[k]) == startHash.end()){ //Se ainda nao passamos.
                vector<vector<int>> pares = twoSum(nums,k+1,-nums[k]);
                for(int par=0;par<pares.size();par++){
                    res.push_back({nums[k],pares[par][0],pares[par][1]});
                }
                startHash[nums[k]]=k;
            }
        }

        return res;

    }

    vector<vector<int>> twoSum(vector<int>& nums, int begin, int target){
        int ini,fim;
        vector<vector<int>> output;
        
        ini = begin;
        fim = nums.size()-1;

        while(ini < fim){
            int soma =  nums[ini] + nums[fim];
            
            if(soma == target){
                output.push_back({nums[ini],nums[fim]});
                while (ini < fim && nums[ini] == nums[ini + 1]) ini++;
                while (ini < fim && nums[fim] == nums[fim - 1]) fim--;
                fim-=1;
                ini+=1;
            }else if(soma > target){
                fim -=1;
            }else{
                ini+=1;
            }
        }

        return output;
    }

};
