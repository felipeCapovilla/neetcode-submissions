class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        if(n < 2){
            return n;
        }

        unordered_set<char> caracteres;

        for(int i=0;i<n;i++){
            caracteres.insert(s[i]);
        }

        int tam=0;
        for(char c : caracteres){
            int r=0;
            int l=0;
            int diff=0;
            while(r < n){
                if(s[r] != c){
                    diff++;
                }

                while(diff > k){
                    if(s[l] != c){
                        diff--;
                    }
                    l++;
                }

                tam = max(tam,r-l+1);
                r++;
            }
        }

        return tam;
        
    }
};
