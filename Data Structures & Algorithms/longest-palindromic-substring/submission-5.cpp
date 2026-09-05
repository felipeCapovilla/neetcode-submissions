class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 1){
            return s;
        }
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        int start_idx=0;
        int tam =1;

        for(int k=0; k<n;k++){
            dp[k][k] = true;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i] == s[j] && (dp[i+1][j-1] || j-i+1 <=2)){
                    dp[i][j]=true;
                    if(j-i+1 > tam){
                        tam = j-i+1;
                        start_idx = i;
                    }
                }
            }
        }

        return s.substr(start_idx,tam);
        
    }
};
