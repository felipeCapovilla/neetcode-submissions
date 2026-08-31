class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        int sumGas,sumCost;
        sumGas=0;
        sumCost=0;

        for(int k=0; k<n;k++){
            sumGas+=gas[k];
        }

        for(int k=0; k<n;k++){
            sumCost+=cost[k];
        }

        if(sumGas < sumCost){
            return -1;
        }


        int start_idx =0;
        int total=0;

        for(int k=0; k<n;k++){
            total+=(gas[k] - cost[k]);
            if(total <0){
                total=0;
                start_idx=k+1;
            }
        }

        return start_idx;
        
    }
};
