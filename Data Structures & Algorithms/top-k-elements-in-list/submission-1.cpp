class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> heap;
        
        for(int n=0; n<nums.size();n++){
            hash[nums[n]]++;
        }

        for(auto& par : hash){
            heap.push({par.second,par.first});
            if(heap.size() > k){
                heap.pop();
            }
        }

        vector<int> out;
        while(!heap.empty()){
            out.push_back(heap.top().second);
            heap.pop();
        }

        return out;


        
    }
};
