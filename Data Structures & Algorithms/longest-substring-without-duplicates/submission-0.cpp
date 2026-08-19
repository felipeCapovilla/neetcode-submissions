class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ini,fim;
        int maxSize;

        maxSize = ini = fim=0;

        unordered_map<char,int> hash;

        while(fim < s.size()){
            hash[s[fim]]+=1;
            while(hash[s[fim]] > 1){
                hash[s[ini]]--;
                ini++;
            }
            maxSize = max(maxSize,fim-ini+1); 
            fim++;

        }

        return maxSize;

        
    }
};
