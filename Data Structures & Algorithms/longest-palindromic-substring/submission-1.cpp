class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        int tam=0;
        int start_idx=0;

        for(int i=0; i<n;i++){
            int r=i;
            int l=i;

            while(r < n && l >=0){
                if(s[r] == s[l]){
                    if(r-l+1 > tam){
                        start_idx = l;
                        tam = max(tam,r-l+1);
                    }

                }
                else{
                    break;
                }

                r++;
                l--;
            }


            r = i+1;
            l=i;

            while(r<n && l >=0){
                if(s[r] == s[l]){
                    if(r-l+1 > tam){
                        start_idx = l;
                        tam = max(tam,r-l+1);
                    }

                }else{
                    break;
                }

                r++;
                l--;
            }
        }

        return s.substr(start_idx,tam);
        
    }
};
