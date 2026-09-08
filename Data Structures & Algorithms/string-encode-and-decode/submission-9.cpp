class Solution {
public:

    string encode(vector<string>& strs) {

        if(strs.size() == 0){
            return "";
        }
        string out;

        for(const string& str : strs){
            string tam = to_string(str.size());
            out+=tam;
            out.push_back('*');
            out+=str;
        }

        return out;

    }

    vector<string> decode(string s) {

        if(s.size() ==0){
            return {};
        }

        vector<string> output;

        int l=0;
        while(l < s.size()-1){
            int r=l;

            while(isdigit(s[r])){
                r++;
            }

            int tam = stoi(s.substr(l,r-l));
            l=r+1;

            string curr = s.substr(l,tam);
            output.push_back(curr);

            l+=tam;
            r=l;
        }

        return output;

    }
};
