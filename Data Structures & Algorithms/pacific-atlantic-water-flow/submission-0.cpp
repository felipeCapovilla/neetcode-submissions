class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m,n;
        m = heights.size();
        n = heights[0].size();
        
        vector<vector<int>> v1(m,vector<int>(n,0));
        vector<vector<int>> v2(m,vector<int>(n,0));

        set<pair<int,int>> pacifico;
        set<pair<int,int>> atlantico;

        for(int i=0;i<m;i++){
            dfs(heights,v1,i,0,-1,pacifico);
            dfs(heights,v2,i,n-1,-1,atlantico);
        }

        for(int j=0;j<n;j++){
            dfs(heights,v1,0,j,-1,pacifico);
            dfs(heights,v2,m-1,j,-1,atlantico);
        }

        vector<vector<int>> out;

        for(auto& par : pacifico){
            if(atlantico.count(par)){
                out.push_back({par.first,par.second});
            }
        }

        return out;
    }

    //Vamos fazer um DFS buscando todas as celulas com altura maior ou igual partindo da botda do pacifico. (inundar pacifico)
    void dfs(vector<vector<int>>& h, vector<vector<int>>& v, int i, int j, int last_hight, set<pair<int,int>>& conj){
        if(h[i][j] < last_hight || v[i][j] == 1){
            return;
        }

        
        v[i][j] = 1;
        conj.insert({i,j});

        if(i+1 < h.size() && v[i+1][j] ==0){
            dfs(h,v,i+1,j,h[i][j],conj);
        }
        if(i-1 >=0 && v[i-1][j] ==0){
            dfs(h,v,i-1,j,h[i][j],conj);
        }
        if(j+1 < h[0].size() && v[i][j+1] ==0){
            dfs(h,v,i,j+1,h[i][j],conj);
        }
        if(j-1 >=0 && v[i][j-1] ==0){
            dfs(h,v,i,j-1,h[i][j],conj);
        }
    }
};
