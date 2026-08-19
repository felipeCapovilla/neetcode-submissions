class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-Heap armazenando: {distancia_quadrada, {x, y}}
        priority_queue<pair<int, pair<int, int>>> heap;
        
        for(int i = 0; i < points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            
            // Calcula a distância ao quadrado (sem sqrt)
            int dist = (x * x) + (y * y);
            
            // Insere o ponto no heap
            heap.push({dist, {x, y}});
            
            // Se o heap passar de k elementos, removemos o mais distante (o topo)
            if(heap.size() > k){
                heap.pop();
            }
        }

        vector<vector<int>> out;
        while(!heap.empty()){
            auto [dist, coords] = heap.top();
            heap.pop();
            out.push_back({coords.first, coords.second});
        }

        return out;
    }
};