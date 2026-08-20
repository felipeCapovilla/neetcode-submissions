class Solution {
public:
    bool isPalindrome(string s) {
        string adjusted = "";

        for(int k=0; k<s.size();k++){
            if(isalnum(s[k])){
                adjusted+=s[k];
            }
        }

        int ini=0;
        int fim = adjusted.size()-1;
        cout << adjusted;
        while(ini < fim){
            if(tolower(adjusted[ini]) != tolower(adjusted[fim])){
                return false;
            }

            ini++;
            fim--;
        }

        return true;
        
    }
};
