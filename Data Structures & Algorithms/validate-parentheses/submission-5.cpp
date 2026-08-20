class Solution {
public:
    bool isValid(string s) {
        
        if(s.size() % 2 ==1){
            return false;
        }
        stack<char> pilha;

        for(int k=0; k<s.size();k++){
            if(s[k] == '('){
                pilha.push(')');
            }else if(s[k] == '['){
                pilha.push(']');
            }else if(s[k] == '{'){
                pilha.push('}');
            }else{

                if(pilha.empty()){
                    return false;
                }
                if(s[k] != pilha.top()){
                    return false;
                }
                pilha.pop();

            }
        }

        if(!pilha.empty()){
            return false;
        }
        return true;
        
    }
};
