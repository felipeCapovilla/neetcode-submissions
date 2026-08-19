class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> h1,h2;
        
        for(int i=0;i<s.size();i++){
            h1[s[i]]++;
        }

        for(int j=0;j<t.size();j++){
            h2[t[j]]++;
        }

        return h1==h2;
        
        
    }
};
