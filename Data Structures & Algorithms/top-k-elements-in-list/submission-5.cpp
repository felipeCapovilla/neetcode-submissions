class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> hash;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;


        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }

        for(auto par: hash){
            if(heap.size() < k){
                heap.push({par.second,par.first});
            }else{
                if(heap.top().first < par.second){
                    heap.pop();
                    heap.push({par.second,par.first});
                }
            }
        }

        vector<int> output;
        while(!heap.empty()){
            output.push_back(heap.top().second);
            heap.pop();
        }

        return output;




        
    }
};
