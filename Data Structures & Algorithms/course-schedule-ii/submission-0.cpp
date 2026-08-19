class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses);
        int course,pre;

        for(int k=0; k<prerequisites.size(); k++){
            course = prerequisites[k][0];
            pre = prerequisites[k][1];

            adj[pre].push_back(course);
            degree[course]++;
        }   


        queue<int> fila;
        for(int k=0; k<numCourses; k++){
            if(degree[k] ==0){
                fila.push(k);
            }
        }

        int cont=0;
        while(!fila.empty()){
            int val = fila.front();
            fila.pop();
            cont++;
            order.push_back(val);

            for(auto node : adj[val]){
                degree[node]--;
                if(degree[node] ==0){
                    fila.push(node);
                }
            }

        }

        if(cont == numCourses){
            return order;
        }
        return {};


    }
};
