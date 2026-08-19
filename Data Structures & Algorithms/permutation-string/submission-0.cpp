class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_multiset<char> c1;
        unordered_multiset<char> c2;
        

        for(int k=0; k<s1.size();k++){
            c1.insert(s1[k]);
        }

        int ini,fim;
        ini =0 ;
        fim = s1.size()-1;
        
        while(fim < s2.size()){
            for(int i=ini;i<=fim;i++){
                c2.insert(s2[i]);
            }
            if(c2 == c1){
                return true;
            }
            fim++;
            ini++;
            c2.clear();
        }

        return false;

        
    }
};
