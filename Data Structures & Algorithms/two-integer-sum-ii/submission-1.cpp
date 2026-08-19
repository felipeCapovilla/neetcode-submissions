class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int ini,fim,soma;
        ini =0;
        fim = numbers.size()-1;

        while(ini < fim){
            soma = numbers[ini] + numbers[fim];
            if(soma == target){
                return {ini+1,fim+1};
            }else if(soma > target){
                fim--;
            }else{
                ini++;
            }

        }
        
    }
};
