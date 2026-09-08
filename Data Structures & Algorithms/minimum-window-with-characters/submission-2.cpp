class Solution {
public:



    int computeDiff(unordered_map<char,int>& goal, unordered_map<char,int>& curr){
        int cont=0;
        for(auto par : goal){
            if(!curr.count(par.first)){
                cont+=par.second;
            }else{
                if(curr[par.first] >= par.second){
                    continue;
                }else{
                    cont+=par.second - curr[par.first];
                }
            }
        }

        return cont;
    }


    string minWindow(string s, string t) {

        if(s.size() < t.size()){
            return "";
        }

        unordered_map<char,int>goal;
        unordered_map<char,int> curr;

        for(int k=0;k<t.size();k++){
            goal[t[k]]++;
        }

        int start_idx =-1;
        int tam = INT_MAX;

        int r=0;
        int l=0;

        while(r < s.size()){
            curr[s[r]]++;
            
            while(computeDiff(goal,curr)==0){
                if(r-l+1 < tam){
                    tam = r-l+1;
                    start_idx=l;
                }

                if(curr[s[l]]==1){
                    curr.erase(s[l]);
                }else{
                    curr[s[l]]--;
                }
                l++;
            }

            r++;
        }
        
        return start_idx == -1 ? "" : s.substr(start_idx,tam);
    }
};
