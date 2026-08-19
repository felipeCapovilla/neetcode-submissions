class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m,n;
        m = grid.size();
        n = grid[0].size();



        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(grid[i][j] ==0){
                    dfs(grid,i,j);
                }
            }
        }
        
    }

    void dfs(vector<vector<int>>& grid,int i, int j){

        queue<pair<int,int>> fila;
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),0));
        fila.push({i,j});
        v[i][j] = 1;

        int tam;
        int m,n;
        m = grid.size();
        n = grid[0].size();
        int dist =1;

        while(!fila.empty()){
            tam = fila.size();


            for(int k=0; k<tam;k++){
                auto [x,y] = fila.front();
                v[x][y] =1;
                fila.pop();

                if(x+1 < m && v[x+1][y] == 0){ //Verifico se esta dentro do array e foi visitado.
                    if(grid[x+1][y] > 1){ //Verifico se eh terra.
                        
                        fila.push({x+1,y});
                        v[x+1][y] =1;
                        grid[x+1][y] = min(dist,grid[x+1][y]);
                    }
                }

                if(x-1 >=0 && v[x-1][y] == 0){ //Verifico se esta dentro do array e foi visitado.
                    if(grid[x-1][y] > 1){ //Verifico se eh terra.
                        
                        fila.push({x-1,y});
                        v[x-1][y] =1;
                        grid[x-1][y] = min(dist,grid[x-1][y]);
                    }
                }

                if(y+1 < n && v[x][y+1] == 0){ //Verifico se esta dentro do array e foi visitado.
                    if(grid[x][y+1] > 1){ //Verifico se eh terra.
                        
                        fila.push({x,y+1});
                        v[x][y+1] =1;
                        grid[x][y+1] = min(dist,grid[x][y+1]);
                    }
                }

                if(y-1 >=0 && v[x][y-1] == 0){ //Verifico se esta dentro do array e foi visitado.
                    if(grid[x][y-1] > 1){ //Verifico se eh terra.
                        
                        fila.push({x,y-1});
                        v[x][y-1] =1;
                        grid[x][y-1] = min(dist,grid[x][y-1]);
                    }
                }


            }
            dist++;
            
        }
        
    }
};
