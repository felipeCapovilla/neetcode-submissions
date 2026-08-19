class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> v(n,0);
        int cont =0;
        int node_a, node_b;

        for(int k=0; k<edges.size();k++){
            node_a = edges[k][0];
            node_b = edges[k][1];

            adj[node_a].push_back(node_b);
            adj[node_b].push_back(node_a);
        }

        for(int k=0; k<n;k++){
            if(v[k] ==0){
                cont++;
                dfs(k,adj,v);
            }
        }


        return cont;
        


    }

    void dfs(int curr, vector<vector<int>>& adj, vector<int>& v){
        if(v[curr] == 1){
            return;
        }

        v[curr] =1;
        for(int node : adj[curr]){
            dfs(node, adj, v);
        }
    }

};
