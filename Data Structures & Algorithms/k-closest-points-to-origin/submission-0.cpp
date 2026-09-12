class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      priority_queue<
      pair<int,int>,
      vector<pair<int,int>>,
      greater<pair<int,int>>>pq;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            int distance = x*x + y*y;

            pq.push({distance,i});
        }
        while(!pq.empty() && k!=0){
            auto top = pq.top();
            pq.pop();
            int index = top.second;

            ans.push_back(points[index]);
            k--;
        }
        return ans;
    }
};
