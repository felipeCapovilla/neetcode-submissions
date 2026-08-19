class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;

        string sorted;
        for(int k=0; k<strs.size(); k++){
            sorted = strs[k];
            sort(sorted.begin(),sorted.end());
            hash[sorted].push_back(strs[k]);
        }

        vector<vector<string>> output;
        for(auto& par : hash){
            output.push_back(par.second);
        }
        return output;
    }
};
