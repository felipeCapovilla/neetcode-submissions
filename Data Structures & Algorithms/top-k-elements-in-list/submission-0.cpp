class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;

        for(int j=0; j<nums.size(); j++){
            hash[nums[j]]+=1;
        }

        vector<pair<int,int>> analise;
        
        for(auto& par : hash){
            int ele = par.first;
            int freq = par.second;
        
            analise.push_back({freq,ele});
        }

        sort(analise.begin(),analise.end(),greater<pair<int,int>>());
        vector<int> output;


        for(int j=0;j<k;j++){
            output.push_back(analise[j].second);
        }

        return output;

    }
};
