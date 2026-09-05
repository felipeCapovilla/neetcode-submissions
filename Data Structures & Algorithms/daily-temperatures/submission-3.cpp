class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        if(n == 0){
            return {};
        }
        if(n == 1){
            return {0};
        }

        vector<int> out(n,0);
        stack<int> pilha;
        pilha.push(n-1);

        for(int k=n-2;k>=0;k--){
            while(!pilha.empty() && temperatures[pilha.top()] <= temperatures[k]){
                pilha.pop();
            }

            if(!pilha.empty()){
                out[k] = pilha.top() -k;
            }

            pilha.push(k);
        }
        
        return out;
    }
};
