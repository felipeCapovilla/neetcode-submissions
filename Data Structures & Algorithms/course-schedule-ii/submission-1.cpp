class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses);
        vector<vector<int>> graph(numCourses);
        queue<int> fila;
        vector<int> order;
        int topCounter=0;

        for(int k=0; k<prerequisites.size();k++){
            int out,in;
            
            out = prerequisites[k][1];
            in = prerequisites[k][0];
            in_degree[in]++;

            graph[out].push_back(in);
        }

        for(int i=0; i<numCourses;i++){
            if(in_degree[i] == 0){
                fila.push(i);
            }
        }

        while(!fila.empty()){
            int curr = fila.front();
            order.push_back(curr);
            fila.pop();

            for(int node : graph[curr]){
                in_degree[node]--;
                if(in_degree[node] ==0){
                    fila.push(node);
                }
            }

            topCounter++;
        }

        vector<int> none = {};
        return topCounter == numCourses ? order : none;

    }
};
