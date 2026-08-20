class Solution {
public:
    int maxArea(vector<int>& heights) {

        int ini,fim,maxArea,n;
        n = heights.size();
        ini =0;
        fim = n-1;
        maxArea=0;


        while(ini < fim){
            int area = (fim-ini)*min(heights[fim],heights[ini]);
            maxArea = max(area,maxArea);

            if(heights[ini] > heights[fim]){
                fim--;
            }else{
                ini++;
            }
        }

        return maxArea;
        
    }
};
