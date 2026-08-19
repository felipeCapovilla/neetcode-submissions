class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){
            return 0;
        }

        int n,m;
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        int islands=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    bfs(i,j,grid,visited);
                    islands++;
                }

            }
        }

        return islands;
        
    }


    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& v){
        
        queue<pair<int,int>> fila;
        
        int n,m;
        n = grid.size();
        m=grid[0].size();

        fila.push({i,j});
        v[i][j] =1;

        while(!fila.empty()){
            auto [a,b] = fila.front();
            fila.pop();

            if(a+1 < n && b < m){ //Limites;
                 if(grid[a+1][b] == '1' && !v[a+1][b]){
                    fila.push({a+1,b});
                    v[a+1][b] = 1;
                 }
            }

            if(a < n && b+1 < m){ //Limites;
                 if(grid[a][b+1] == '1' && !v[a][b+1]){
                    fila.push({a,b+1});
                    v[a][b+1] = 1;
                 }
            }

            if(a-1 >= 0 && b < m){ //Limites;
                 if(grid[a-1][b] == '1' && !v[a-1][b]){
                    fila.push({a-1,b});
                    v[a-1][b] = 1;
                 }
            }


            if(a < n && b-1 >= 0){ //Limites;
                 if(grid[a][b-1] == '1' && !v[a][b-1]){
                    fila.push({a,b-1});
                    v[a][b-1] =1;
                 }
            }
            


        }

    }


};
