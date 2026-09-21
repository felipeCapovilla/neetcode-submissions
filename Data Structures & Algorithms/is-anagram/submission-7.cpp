class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> hash;

        for(char c : s){
            hash[c]++;
        }

        for(char c : t){
            if(!hash.count(c)){
                return false;
            }

            if(hash[c] == 1){
                hash.erase(c);
            }else{
                hash[c]--;
            }
        }

        return hash.size()==0;



        
    }
};
