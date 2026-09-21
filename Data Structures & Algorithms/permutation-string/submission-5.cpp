class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int m = s1.size();
        int n = s2.size();

        if(n<m){
            return false;
        }

        unordered_map<char,int> h1;
        unordered_map<char,int> h2;

        for(int c : s1){
            h1[c]++;
        }

        int l=0;
        int r=m-1;

        for(int k=0; k<r;k++){
            h2[s2[k]]++;
        }

        while(r<s2.size()){

            
            h2[s2[r]]++;

            if(h1==h2){
                return true;
            }

            if(h2[s2[l]] == 1){
                h2.erase(s2[l]);
            }else{
                h2[s2[l]]--;
            }

            r++;
            l++;
            

        }

        return false;

        
    }
};
