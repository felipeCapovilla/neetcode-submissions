class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_set<char> caracteres(s.begin(),s.end());

        int tam=0;
        for(auto c : caracteres){
            int cont=0;
            int l=0;

            for(int r=0;r<s.size();r++){

                if(s[r] == c){
                    cont++;
                }

                while((r-l+1)-cont > k){
                    if(s[l] == c){
                        cont--;
                    }
                    l++;
                }
                tam = max(tam,r-l+1);
            }

        }

        return tam;


        
    }
};
