class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0){
            return "";
        }

        if(strs.size()==1){
            return strs[0];
        }

        string ini = lcs(strs[0],strs[1]);
        for(int k=2;k<strs.size();k++){
            ini = lcs(strs[k],ini);
        }

        return ini;
        
    }

    string lcs(string a, string b){
        int p=0;
        int q=0;


        while(p<a.size() && q<b.size()){
            if(a[p] != b[q]){
                break;
            }
            p++;
            q++;
        }

        return a.substr(0,p);
    }
};