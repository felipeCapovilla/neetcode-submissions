class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
            int l=0;
    int r= numbers.size()-1;

    vector<int> answer(2);

    while(l<r){
        int sum = numbers[l]+numbers[r];
        if(sum == target){
            break;
        }
        if(sum > target){
            r--;
        }else{
            l++;
        }
    }

    answer[0] = l+1;
    answer[1] = r+1;
    return answer;
    }
};
