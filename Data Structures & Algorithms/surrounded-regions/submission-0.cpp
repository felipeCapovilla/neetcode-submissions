class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m,n;
        m = board.size();
        n = board[0].size();

        vector<vector<int>> v(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                bfs(board,v,i,0);
            }
            if(board[i][n-1] == 'O'){
                bfs(board,v,i,n-1);
            }
        }

        for(int j=0;j<n;j++){
            if(board[0][j] == 'O'){
                bfs(board,v,0,j);
            }
            if(board[m-1][j] == 'O'){
                bfs(board,v,m-1,j);
            }
        }

        verify(board);


    }


    void bfs(vector<vector<char>>& b, vector<vector<int>>&v, int i, int j){
        
        queue<pair<int,int>>fila;
        fila.push({i,j});
        
        v[i][j] =1;

        while(!fila.empty()){
            auto [x,y] = fila.front();
            b[x][y] = 'b';
            fila.pop();

            if(x+1 < b.size() && v[x+1][y] == 0 && b[x+1][y] == 'O'){
                fila.push({x+1,y});
                v[x+1][y] =1;
            }

            if(x-1 >=0 && v[x-1][y] == 0 && b[x-1][y] == 'O'){
                fila.push({x-1,y});
                v[x-1][y] =1;
            }

            if(y+1 < b[0].size() && v[x][y+1] == 0 && b[x][y+1]=='O'){
                fila.push({x,y+1});
                v[x][y+1] =1;
            }

            if(y-1 >=0 && v[x][y-1] == 0 && b[x][y-1]=='O'){
                fila.push({x,y-1});
                v[x][y-1] =1;
            }


        }   

    }


    void verify(vector<vector<char>>& v){
        int m,n;
        m = v.size();
        n = v[0].size();


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j] == 'O'){
                    v[i][j] = 'X';
                }
                if(v[i][j] == 'b'){
                    v[i][j] = 'O';
                }
            }
        }
    }
};
