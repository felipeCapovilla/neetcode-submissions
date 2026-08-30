class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // dp[i][j] = distância entre word1[0..i-1] e word2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base cases: transformar string de tamanho k em string vazia custa k deleções/inserções
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j - 1], // Substituição
                        dp[i - 1][j],     // Deleção
                        dp[i][j - 1]      // Inserção
                    });
                }
            }
        }

        return dp[m][n];
    }
};