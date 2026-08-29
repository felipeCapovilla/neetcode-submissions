class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int tam=0;
        int start_idx=0;

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(j-i+1 > tam){
                                            tam = max(tam,j-i+1);
                                            start_idx=i;
                    }

                }
            }
        }

        return s.substr(start_idx,tam);


    }
};
