class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = s.size();

        int r=n-1;
        while(!isalnum(s[r])){
            r--;
        }

        int cont=0;
        while(isalnum(s[r])){
            cont++;
            r--;
        }

        return cont;
        
    }
};