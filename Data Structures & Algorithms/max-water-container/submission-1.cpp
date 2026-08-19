class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ini,fim;
        int n = heights.size();
        int maxA =0;

        ini = 0;
        fim = n-1;

        while(ini < fim){
            int altura = min(heights[ini],heights[fim]);
            int currArea = (fim-ini)*altura;
            maxA = max(maxA,currArea);

            if(heights[ini] < heights[fim]){
                ini++;
            }else{
                fim--;
            }
        }

        return maxA;
        
    }
};
