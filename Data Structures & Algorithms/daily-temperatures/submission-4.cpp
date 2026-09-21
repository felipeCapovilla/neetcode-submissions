class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> pilha;
        int n = temperatures.size();
        vector<int> output(n,0);

        for(int k=n-1;k>=0;k--){

            while(!pilha.empty()){
                if(temperatures[k] >= temperatures[pilha.top()]){
                    pilha.pop();
                }else{
                    output[k] = pilha.top()-k;
                    pilha.push(k);
                    break;
                }
            }

            if(pilha.empty()){
                pilha.push(k);
            }
        }

        return output;

        
    }
};
