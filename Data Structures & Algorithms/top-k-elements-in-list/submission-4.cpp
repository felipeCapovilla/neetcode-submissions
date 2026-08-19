class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> hash;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }



        for(auto element : hash){
            if(minHeap.size() < k){
                minHeap.push({element.second,element.first});
            }else{
                if(element.second > minHeap.top().first){
                    minHeap.pop();
                    minHeap.push({element.second,element.first});
                }
            }
        }

        vector<int> out;
        while(!minHeap.empty()){
            auto [freq, element] = minHeap.top();
            minHeap.pop();
            out.push_back(element);
        }

        return out;


        
    }
};
