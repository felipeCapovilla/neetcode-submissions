class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ini,fim;
        ini =0;
        fim = numbers.size()-1;

        while(ini < fim){
            int sum = numbers[ini] + numbers[fim];
            if(sum == target){
                return {ini+1,fim+1};
            }else if(sum > target){
                fim--;
           }else{
            ini++;
           }
        }

        return {};
        
    }
};
