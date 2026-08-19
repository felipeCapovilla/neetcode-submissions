class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<int> output;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        
        for(int k=0; k<nums.size();k++){
            hash[nums[k]]++;
        };

        for(auto par : hash){
            if(heap.size() < k){
                heap.push({par.second,par.first});
            }
            else if(par.second > heap.top().first){
                heap.pop();
                heap.push({par.second,par.first});
            }
        }

        while(!heap.empty()){
            auto [freq, element] = heap.top();
            heap.pop();
            output.push_back(element);
        }

        return output;
        
    }
};
