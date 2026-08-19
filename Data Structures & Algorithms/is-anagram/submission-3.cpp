class Solution {
public:
    bool isAnagram(string s, string t) {
    unordered_map<char,int> table;

    for(int k=0; k<s.size();k++){
        table[s[k]]+=1;
    }

    for(int k=0;k<t.size();k++){
        table[t[k]]-=1;
    }

    for(auto& par : table){
        if(par.second != 0) return false;
    }
    return true;
    }
};
