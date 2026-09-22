class Solution {
public:
    int scoreOfString(string s) {

        if(s.size() ==0){
            return 0;
        }


        int cont=0;

        for(int k=0;k<s.size()-1;k++){
            cont+=abs(s[k+1] - s[k]);
        }

        return cont;
        
    }
};