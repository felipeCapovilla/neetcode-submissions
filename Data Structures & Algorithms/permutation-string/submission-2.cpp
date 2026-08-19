class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> comp;
        unordered_map<char,int> substr;
        int ini,fim;

        ini = 0;
        fim = s1.size()-1;

        for(int k=0; k<=fim;k++){
            comp[s1[k]]++;
            substr[s2[k]]++;
        }

        while(fim < s2.size()){
            if(comp == substr){
                return true;
            }

            substr[s2[ini]]--;
            if(substr[s2[ini]] ==0){
                substr.erase(s2[ini]);
            }
            ini++;
            fim++;
            
            if(fim < s2.size()){
                substr[s2[fim]]++;
            }

        }

        return false;


    }
};
