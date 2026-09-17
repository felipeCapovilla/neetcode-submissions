class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cont=0;

        int m =grid.size();
        int n = grid[0].size();

        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j] == '1'){
                    bfs(grid,i,j);
                    cont++;
                }
            }
        }

        return cont;
        
    }

    void bfs(vector<vector<char>>& grid, int x, int y){

        queue<pair<int,int>> fila;
        int m = grid.size();
        int n = grid[0].size();
        
        fila.push({x,y});
        grid[x][y] = '3';
        
        while(!fila.empty()){

            auto [i,j] = fila.front();
            fila.pop();

            if(i+1 < m && grid[i+1][j] == '1'){
                grid[i+1][j] = '3';
                fila.push({i+1,j});
            }
            if(j+1 < n && grid[i][j+1] == '1'){
                grid[i][j+1] = '3';
                fila.push({i,j+1});
            }
            if(j-1 >=0 && grid[i][j-1] == '1'){
                grid[i][j-1] = '3';
                fila.push({i,j-1});
            }
            if(i-1 >=0 && grid[i-1][j] == '1'){
                grid[i-1][j] = '3';
                fila.push({i-1,j});
            }

        }
    }
};
