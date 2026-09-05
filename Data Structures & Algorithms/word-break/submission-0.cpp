class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());

        int max_size =0;
        for(string word : wordDict){
            max_size = max(max_size,(int)word.size());
        }
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;

        for(int i=1;i<=n;i++){
            for(int j=i-1;j>= max(0,i-max_size);j--){
                if(dp[j] && hash.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[n];

        
    }
};
