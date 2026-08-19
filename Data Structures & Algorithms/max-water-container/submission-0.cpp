class Solution {
public:
    int maxArea(vector<int>& heights) {

        int max=0;

        int ini,fim;
        ini = 0;
        fim = heights.size()-1;

        while(ini < fim){
            int area = min(heights[ini],heights[fim]) * (fim-ini);
            if(area > max){
                max = area;
            }

            if(heights[ini] <heights[fim] ){
                ini+=1;
            }else{
                fim-=1;
            }


        }

        return max;        


    }
};
