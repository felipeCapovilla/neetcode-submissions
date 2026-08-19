class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        if(stones.size() == 0){
            return 0;
        }else if(stones.size() == 1){
            return stones[0];
        }

        for(int k=0; k<stones.size();k++){
            maxHeap.push(stones[k]);
        }

        while(maxHeap.size() > 1){
            int p1,p2;

            p1 = maxHeap.top();
            maxHeap.pop();

            p2 = maxHeap.top();
            maxHeap.pop();

            if(p1 == p2){
                continue;
            }else if(p1 > p2){
                maxHeap.push(p1-p2);
            }else{
                maxHeap.push(p2-p1);
            }

        }

        int out;
        out = maxHeap.top();
        if(maxHeap.size() == 0){
            return 0;
        }
        return out;
        
    }
};
