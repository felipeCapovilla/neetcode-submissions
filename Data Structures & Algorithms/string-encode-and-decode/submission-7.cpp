class Solution {
public:

    string encode(vector<string>& strs) {

        string output= "";

        for(int k=0;k<strs.size();k++){
            output+=(to_string(strs[k].size()) + '#' + strs[k]);
        }

        return output;

    }

    vector<string> decode(string s) {

        vector<string> answer;
        int k=0;

        while(k < s.size()){
            int j=k;
            while(s[j] != '#'){
                j++;
            }

            int size = stoi(s.substr(k,j-k));
            string str = s.substr(j+1,size);
            answer.push_back(str);

            k = j+1+size;
        }

        return answer;

    }
};
