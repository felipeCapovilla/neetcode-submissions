class Solution {
public:
    bool isPalindrome(string s) {
        int ini=0;
        int fim = s.size()-1;

        while(ini <= fim){
            if(isalnum(s[ini]) && isalnum(s[fim])){
                if(tolower(s[ini]) != tolower(s[fim])){
                    return false;
                }
                ini++;
                fim--;
            }else if(!isalnum(s[ini])){
                ini++;
            }else if(!isalnum(s[fim])){
                fim--;
            }else{

                ini++;
                fim--;
            }
        }

        return true;
        
    }
};
