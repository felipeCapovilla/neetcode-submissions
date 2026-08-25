class Solution {
public:
    int findMin(vector<int> &v) {

        int r,l,out;
        l=0;
        r=v.size()-1;
        out = v[0];

        while(r >= l){
            if(v[l] < v[r]){
                out = min(out,v[l]);
                return out;
            }

            int mid = (r+l)/2;
            out = min(v[mid],out);
            if(v[mid] < v[r]){
                r = mid-1;

            }else{
                l= mid+1;
            }
        }

        return out;
        
    }
};
