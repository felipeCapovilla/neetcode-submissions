class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        int nEdges = edges.size();
        if(nEdges > n-1){
            return false;
        }

        vector<vector<int>> adj(n);
        vector<int> v(n,0);

        for(int k=0; k<nEdges; k++){
            int node_a,node_b;
        
            node_a = edges[k][0];
            node_b = edges[k][1];

            adj[node_a].push_back(node_b);
            adj[node_b].push_back(node_a);
        }

        if(!dfs(0,-1,adj,v)){
            return false;
        }

        for(int k=0; k<v.size();k++){
            if(v[k] == 0){
                return false;
            }
        }

        return true;

    }

    bool dfs(int curr, int pai, vector<vector<int>>& adj, vector<int>& v){
        if(v[curr] == 1){
            return false;
        }

        v[curr] =1;
        for(int node : adj[curr]){
            if(node == pai){
                continue;
            }
            if(!dfs(node,curr,adj,v)){
                return false;
            }
        }

        return true;
    }

    
};
