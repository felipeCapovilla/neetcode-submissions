class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;

        for(int k=0; k<strs.size();k++){
            string curr = strs[k];
            sort(curr.begin(),curr.end());
            hash[curr].push_back(strs[k]);
        }

        vector<vector<string>> out;
        for(auto par : hash){   
            out.push_back(par.second);
        }

        return out;


        
    }
};
