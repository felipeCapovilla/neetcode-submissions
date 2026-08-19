class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> anagramMap;
    
    for(auto str : strs){
        string key = str;
        sort(key.begin(),key.end());

        anagramMap[key].push_back(str);
    }

    vector<vector<string>> res;

    for(auto& par : anagramMap){
        res.push_back(std::move(par.second));
    }

    return res;      
    }
};
