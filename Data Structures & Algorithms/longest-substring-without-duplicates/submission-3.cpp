class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int tam=0;
        int r=0;
        int l=0;

        while(r < s.size()){

            hash[s[r]]++;
            while(hash[s[r]] > 1){
                if(hash[s[l]] == 1){
                    hash.erase(s[l]);
                }else{
                    hash[s[l]]--;
                }
                l++;
            }

            tam = max(tam,r-l+1);
            r++;
        }

        return tam;
        
    }
};
