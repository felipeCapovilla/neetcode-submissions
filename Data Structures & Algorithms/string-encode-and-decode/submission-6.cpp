class Solution {
public:



    string encode(vector<string>& strs) {

        string out = "";
        int size=0;

        for(int k=0;k<strs.size();k++){
            size = strs[k].size();
            out+=to_string(size);
            out+='#';
            out+=strs[k];    
        }

        return out;

    }

vector<string> decode(string s) {
        vector<string> out;
        int i = 0;

        while (i < s.size()) {
            // Find the delimiter '#'
            int j = s.find('#', i);
            
            // Extract the length of the next string
            int length = stoi(s.substr(i, j - i));
            
            // Extract the exact string using length
            out.push_back(s.substr(j + 1, length));
            
            // Advance pointer past length + delimiter + string
            i = j + 1 + length;
        }

        return out;
    }
};
