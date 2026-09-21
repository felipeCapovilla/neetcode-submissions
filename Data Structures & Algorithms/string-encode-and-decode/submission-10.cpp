class Solution {
public:

    string encode(vector<string>& strs) {
        string output = "";

        for(string str : strs){
            string tam = to_string(str.size());
            output+=tam;
            output+="*";
            output+=str;
        }

        return output;

    }

    vector<string> decode(string s) {

        vector<string> output;

        int r=0;
        int l=0;
        
        while(r<s.size()){
            
            int l=r;

            while(isdigit(s[r])){
                r++;
            }

            int tam = stoi(s.substr(l,r-l));
            r++;

            string curr_string = s.substr(r,tam);
            output.push_back(curr_string);
            r+=tam;
        }

        return output;
    }
};
