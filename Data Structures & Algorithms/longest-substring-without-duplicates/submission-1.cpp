class Solution {
public:
    int lengthOfLongestSubstring(string s) {//Expandir a janela enquanto nao tem repetidos e tirar ate nao ter mais a partir de quando tiver.

        if(s.size() == 0){
            return 0;
        }
        unordered_map<char,int> hash;
        int ini,fim;

        ini=0;
        fim=0;

        int size=0;

        while(fim < s.size()){
            if(!hash.count(s[fim])){ //Ainda nao tem.
                hash[s[fim]]++;
            }else{
                hash[s[fim]]++;
                while(hash[s[fim]] > 1){
                    hash[s[ini]]--;
                    ini++;
                }
            }
            fim++;
            size = max(size,fim-ini);

            
        }

        return size;
        
    }
};
