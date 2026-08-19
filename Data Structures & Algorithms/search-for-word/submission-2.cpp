class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n,m;
        n = board.size();
        m = board[0].size();

        //vector<vector<int>>(n,vector<int>(m,0));
        vector<vector<int>>v(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(dfs(i,j,0,word,board,v)){
                    return true;
                }
            }
        }

        return false;


        
    }

    bool dfs(int r, int c, int i, string& word,vector<vector<char>>& board,vector<vector<int>>& v){
        if(i == word.size()){
            return true;
        }
        if((r<0 || r>=board.size()) || (c<0 || c>=board[0].size() || word[i] != board[r][c] || v[r][c] ==1 )){
            return false;
        }

        v[r][c]=1;

        bool p1 = dfs(r+1,c,i+1,word,board,v);
        bool p2= dfs(r-1,c,i+1,word,board,v);
        bool p3=dfs(r,c+1,i+1,word,board,v);
        bool p4=dfs(r,c-1,i+1,word,board,v);
    
        bool res = p1 || p2|| p3 ||p4;
        v[r][c]=0;
        return res;

    
    }
};
