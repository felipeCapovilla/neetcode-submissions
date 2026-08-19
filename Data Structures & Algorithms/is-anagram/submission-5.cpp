class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() ==0 && t.size() ==0){
            return true;
        }else if(s.size() == 0 && t.size() != 0){
            return false;
        }else if(s.size() !=0 && t.size() ==0){
            return false;
        }else{
            unordered_map<char,int> hash;

            for(int i=0;i<s.size();i++){
                hash[s[i]]++;
            }

            for(int j=0; j<t.size();j++){
                hash[t[j]]--;
            }

            for(auto par : hash){
                if(par.second != 0){
                    return false;
                }
            }

            return true;

        }
        
    }
};
