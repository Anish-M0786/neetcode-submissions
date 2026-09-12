class Twitter {
public:
unordered_map<int,unordered_set<int>>followmap;
unordered_map<int,vector<pair<int,int>>>tweetfeed;
int time =0;
    Twitter() {
       
    }
    void postTweet(int userId, int tweetId) {
        time++;
        tweetfeed[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,pair<int,int>>>pq;
            vector<int>ans;
          if(!tweetfeed[userId].empty()){
            int index = tweetfeed[userId].size() -1;
            pq.push({
                tweetfeed[userId][index].first,
                {userId,index}
            });
          }
            for(int followee:followmap[userId]){
                if(!tweetfeed[followee].empty()){
                    int index = tweetfeed[followee].size()-1;
                    pq.push({
                        tweetfeed[followee][index].first,
                        {followee,index}
                    });
                }
            }
                    while(!pq.empty() && ans.size()<10){
                        auto top = pq.top();
                        pq.pop();

                        int time = top.first;
                        int user = top.second.first;
                        int index = top.second.second;

                        int tweetid = tweetfeed[user][index].second;
                        ans.push_back(tweetid);
                        index--;
                        if(index>=0){
                            pq.push({tweetfeed[user][index].first,
                            {user,index}
                        });
                        
                    
                
            }
          }
          
             return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};
