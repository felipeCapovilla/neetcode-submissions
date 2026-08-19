class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        map<int,int> hash;

        for(int k=0; k<n;k++){
            hash[nums[k]]+=1;
        }

        int maxSeq;
        int currSeq;
        int last;
        last = currSeq = maxSeq =0;

        for(auto& par : hash){
            if(par.first == last+1){
                currSeq +=1;
            }else{
                currSeq =1;
            }
            
            maxSeq = max(maxSeq,currSeq);
            last = par.first;

        }

        return maxSeq;
        
    }
};
