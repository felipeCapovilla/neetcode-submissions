class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int l,r;
        int maxL;
        maxL =0;
        string res;

        for(int k=0;k<n;k++){
            
            //Tamanho impar.
            l = r = k;
            while((l>=0 && r < n) && s[l] == s[r]){
                if(r-l+1 > maxL){
                    maxL = r-l+1;
                    res = s.substr(l,r-l+1); 
                }
                l--;
                r++;
            }

            //Tamanho par.
            l = k;
            r = k+1;
            while((l>=0 && r < n) && s[l] == s[r]){
                if(r-l+1 > maxL){
                    maxL = r-l+1;
                    res = s.substr(l,r-l+1); 
                }
                l--;
                r++;
            }


        }

        return res;
    }
};
