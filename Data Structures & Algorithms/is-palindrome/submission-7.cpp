class Solution {
public:
    bool isPalindrome(string s) {
    
    string copy="";
    for(int k=0;k<s.size();k++){
        if(isalnum(s[k])){
            copy+=tolower(s[k]);
        }
    }

    int ini,fim;
    ini =0;
    fim = copy.size()-1;
    cout << copy;

    while(ini < fim){
        if(copy[ini] != copy[fim]){
            return false;
        }

        ini++;
        fim--;
    }

    return true;

    }
};
