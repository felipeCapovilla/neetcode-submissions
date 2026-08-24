class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        unordered_map<char,int> h1,h2;

        for(int j=0;j<n;j++){
            h1[s1[j]]++;
        }

        for(int k=0; k<n-1;k++){
            h2[s2[k]]++;
        }

        int ini=0;
        int fim = n-1;

        while(fim < m){
            h2[s2[fim]]++;

            if(h1 == h2){
                return true;
            }

            if(h2[s2[ini]] == 1){
                h2.erase(s2[ini]);
            }else{
                h2[s2[ini]]--;
            }

            ini++;
            fim++;
        }

        return false;


    }
};
