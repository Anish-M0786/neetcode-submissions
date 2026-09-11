class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int num:stones){
            pq.push(num);
        }
        while(pq.size()>1){
        int d = pq.top();
        pq.pop();
        int m = pq.top();
        pq.pop();
        int diff = abs(d-m);
         if(diff>0){
            pq.push(diff);
         }
        }

        return pq.empty()?0:pq.top();

    }
};
