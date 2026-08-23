class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> hash;
        int n = s.size();
        int l,r,tam;
        tam =0;
        l =0;
        r=0;

        if(n < 2){
            return n;
        }

        while(r < n){
            hash[s[r]]++;
            if(!hash.count(s[r])){
                continue;
            }else{
                while(hash[s[r]] > 1){
                    hash[s[l]]--;
                    l++;
                }
            }
            tam = max(tam,r-l+1);
            r++;
        }

        return tam;
        
    }
};
