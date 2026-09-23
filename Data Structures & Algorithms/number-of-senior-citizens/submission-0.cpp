class Solution {
public:
    int countSeniors(vector<string>& details) {

        int cont=0;
        for(string curr_str : details){
            int curr_age = stoi(curr_str.substr(11,2));
            if(curr_age > 60){
                cont++;
            }
        }

        return cont;
        
    }
};