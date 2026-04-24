class Twitter {
public:

    map<int,vector<pair<int,int>>>dbMap;
    map<int,unordered_set<int>>friendsMap;
    int time;

    Twitter() {
        dbMap.clear();
        friendsMap.clear();
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        dbMap[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {

        priority_queue<vector<int>>maxHeap;
        friendsMap[userId].insert(userId);
        for(auto friendId: friendsMap[userId]){
            if(dbMap.count(friendId)){
                int m = dbMap[friendId].size();
                maxHeap.push({dbMap[friendId][m-1].first, dbMap[friendId][m-1].second, friendId, m-1});
            }
        }
            
        vector<int>ans;
        while(!maxHeap.empty() && ans.size()<10)
        {
            auto vec = maxHeap.top();
            maxHeap.pop();
            int currTime = vec[0] , tweetId = vec[1], friendId = vec[2], idx = vec[3];
            ans.push_back(tweetId);
            if(idx-1>=0){
                maxHeap.push({dbMap[friendId][idx-1].first, dbMap[friendId][idx-1].second, friendId, idx-1});
            }
        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        friendsMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friendsMap[followerId].erase(followeeId);
    }
};
