class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    vector<int> output;
    int l,r;
    l =0;
    r = arr.size()-1;

    while(r-l+1 > k){
        if(abs(arr[r] -  x) > abs(arr[l] -x )){
            r--;
        }else if(abs(arr[r]-x) < abs(arr[l] - x)){
            l++;
        }else{
            if(arr[r] < arr[l]){
                l++;
            }else{
                r--;
            }
        }
    }

    for(int i=l;i<=r;i++){
        output.push_back(arr[i]);
    }

    return output;

    }
};