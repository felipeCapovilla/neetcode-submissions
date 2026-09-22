class Solution {
public:
    bool isSubsequence(string s, string t) {

        int p =0;
        int q=0;

        

        while(p < s.size() && q<t.size()){ 
            if(s[p] == t[q]){
                p++;
                q++;
            }else{
            q++;    
            }
        
        }

        if(p == s.size()){
            return true;
        }

        return false;


        
    }
};