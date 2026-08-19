class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> h1,h2;

        for(int k=0; k<s.size();k++){
            h1[s[k]]++;
        }

        for(int k=0; k<t.size();k++){
            h2[t[k]]++;
        }

        if(h1 == h2){
            return true;
        }

        return false;

    }
};
