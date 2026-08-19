class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses);


        int pre,course;

        for(int k=0; k<prerequisites.size();k++){
            
            pre=prerequisites[k][1];
            course = prerequisites[k][0];
            
            adj[pre].push_back(course);
            degree[course] ++;
        }


        queue<int> fila;
        for(int k=0; k<numCourses;k++){
            if(degree[k] == 0){
                fila.push(k);
            }
        }

        int cont=0;
        while(!fila.empty()){
            int node = fila.front();
            fila.pop();
            cont++;

            for(auto val : adj[node]){
                degree[val]--;
                if(degree[val] == 0){
                    fila.push(val);
                }
            }
        }

        if(cont == numCourses){
            return true;
        }
        return false;





        
    }
};
