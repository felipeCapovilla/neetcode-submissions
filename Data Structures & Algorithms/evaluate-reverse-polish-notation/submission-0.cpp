class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> pilha;
        unordered_set<string>ops = {"+","-","*","/"};

        for(int k=0;k<tokens.size();k++){
            if(!ops.count(tokens[k])){
                int num = stoi(tokens[k]);
                pilha.push(num);    
            }else{
                int first, second,res;

                second = pilha.top();
                pilha.pop();
                first=pilha.top();
                pilha.pop();

                if(tokens[k] == "+"){
                    res = second+first;
                }else if(tokens[k] == "-"){
                    res = first-second;
                }else if(tokens[k] == "*"){
                    res = first*second;
                }else{
                    res = first/second;
                }

                pilha.push(res);

            }

        }

        return pilha.top();
        
    }
};
