class Solution {
public:
    int appendCharacters(string s, string t) {

        int p=0;
        int q=0;

        while(p < s.size() && q<t.size()){
            if(s[p] == t[q]){
                p++;
                q++;
            }else{
                p++;
            }
        }

        return t.size()-q;
        
    }
};