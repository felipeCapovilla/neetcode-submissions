class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        vector<vector<int>> v(3,vector<int>(n,0));

        int maxL=0;
        for(int k=0;k<n;k++){
            v[0][k] = maxL;
            maxL = max(height[k],maxL);
        }

        int maxR=0;
        for(int k=n-1;k>=0;k--){
            v[1][k] = maxR;
            maxR = max(height[k],maxR);
        }

        for(int k=0;k<n;k++){
            v[2][k] = min(v[1][k],v[0][k]);
        }

        vector<int> output(n);

        for(int k=0;k<n;k++){
            output[k] = max(0,v[2][k] - height[k]);
        }

        int sum=0;
        for(int k=0;k<n;k++){
            sum+=output[k];
        }

        return sum;

        
    }
};
