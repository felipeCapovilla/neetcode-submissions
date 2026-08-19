class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> fila;
        int frescas = 0;

        // 1. PASSO 1: Encontrar TODAS as fontes (2) e contar as frescas (1)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    fila.push({i, j}); // Adiciona TODAS as laranjas podres na mesma fila
                } else if (grid[i][j] == 1) {
                    frescas++;
                }
            }
        }

        // Se não há laranjas frescas para estragar, tempo é 0
        if (frescas == 0) return 0;

        int minutos = 0;
        vector<pair<int, int>> direcoes = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // 2. PASSO 2: Multi-Source BFS
        // A condição 'frescas > 0' impede que o tempo suba no último nível vazio
        while (!fila.empty() && frescas > 0) {
            int tamFila = fila.size();

            for (int k = 0; k < tamFila; k++) {
                auto [x, y] = fila.front();
                fila.pop();

                for (auto [dx, dy] : direcoes) {
                    int nx = x + dx;
                    int ny = y + dy;

                    // Se estiver dentro do grid e for uma laranja fresca
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // Apodrece a laranja (funciona como 'visitado')
                        frescas--;
                        fila.push({nx, ny});
                    }
                }
            }
            minutos++; // Incrementa 1 minuto após processar toda a rodada atual
        }

        // 3. PASSO 3: Se sobrou alguma laranja fresca que não foi alcançada, retorna -1
        return frescas == 0 ? minutos : -1;
    }
};