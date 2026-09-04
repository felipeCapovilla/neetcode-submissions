class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        long long r= *max_element(piles.begin(),piles.end());
        long long l=1;
        long long k=1;

        while(r > l){
            k = (l+r)/2;
            long long cont=0;

            for(int i=0;i<piles.size();i++){
                cont+=(piles[i]+k-1)/k;
                if(cont > h){
                    break;
                }
            }

            if(cont > h){
                l = k+1;
            }else{
                r=k;
            }
            

        }

        return r;
    }
};
