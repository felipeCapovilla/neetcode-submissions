class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> out;
        unordered_map<string,vector<string>>hash;

        for(int k=0;k<strs.size();k++){
            string temp = strs[k];
            sort(temp.begin(),temp.end());
            hash[temp].push_back(strs[k]);
        }

        for(auto par : hash){
            out.push_back(par.second);
        }

        return out;


        
    }
};
