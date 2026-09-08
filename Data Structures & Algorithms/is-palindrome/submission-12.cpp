class Solution {
public:
    bool isPalindrome(string s) {

        string formatted;

        for(int k=0;k<s.size();k++){
            if(isalnum(s[k])){
                        formatted.push_back(tolower(s[k]));
             
                         }
        }

        int l=0;
        int r = formatted.size()-1;
        while(r>=l){
            if(formatted[r] != formatted[l]){
                return false;
            }
            r--;
            l++;
        }

        return true;
        
    }
};
