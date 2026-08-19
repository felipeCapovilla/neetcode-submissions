class Solution {
public:

    int maxArea;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        maxArea=0;
        int m,n;
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> v(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(grid,v,i,j);
                }
            }
        }
        
        return maxArea;
    }


    void dfs(vector<vector<int>>& grid, vector<vector<int>>& v, int i, int j){
        
        int area=0;
        int m,n;
        m = grid.size();
        n = grid[0].size();

        queue<pair<int,int>> fila;
        fila.push({i,j});
        v[i][j] = 1; //Marcamos como visitado.

        while(!fila.empty()){
            area++;
            
            auto [x,y] = fila.front();
            fila.pop();

            if(x+1 < m && v[x+1][y] == 0){
                if(grid[x+1][y] == 1){
                    fila.push({x+1,y});
                    v[x+1][y] = 1;
                }
            }

            if(x-1 >=0 && v[x-1][y] == 0){
                if(grid[x-1][y] == 1){
                    fila.push({x-1,y});
                    v[x-1][y] = 1;
                }
            }

            if(y+1 < n && v[x][y+1] == 0){
                if(grid[x][y+1] == 1){
                    fila.push({x,y+1});
                    v[x][y+1] = 1;
                }
            }

            if(y-1 >=0 && v[x][y-1] == 0){
                if(grid[x][y-1] == 1){
                    fila.push({x,y-1});
                    v[x][y-1] = 1;
                }
            }

        }

        maxArea = max(maxArea,area);
        
    }
};
