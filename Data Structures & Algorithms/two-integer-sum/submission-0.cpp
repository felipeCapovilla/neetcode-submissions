class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> output(2);
        int diff;
        int first,second;
        first = second = -1;

        for(int k=0; k<nums.size();k++){
            diff = target-nums[k];
            if(map.find(diff) == map.end()) // diff nao esta no hash, insere atual
            {
                map.insert({nums[k],k});
            }else{
                auto pos = map.find(diff);

                first = pos->second;
                second = k;
                break;

            }

        }

        output[0] = first;
        output[1] = second;
        return output;

    }
};
