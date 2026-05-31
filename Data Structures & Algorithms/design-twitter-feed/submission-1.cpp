class Twitter {
    using maxHeap = priority_queue<pair<int,int>>;
    unordered_map<int, vector<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int time = 1;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if(following.find(userId) == following.end()){
            following[userId].push_back(userId);
        }
        tweets[userId].push_back({tweetId, time++});
    }
    
    vector<int> getNewsFeed(int userId) {
        maxHeap allTweets;
        for(int followee : following[userId]){
            for(auto [tweet, time] : tweets[followee]){
                allTweets.push({time, tweet});
            }
        }
        int top10 = 10;
        vector<int> ans;
        while(!allTweets.empty() && top10--){
            auto [time, tweet] = allTweets.top(); allTweets.pop();
            ans.push_back(tweet);
        }
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        auto& vec = following[followerId];
        if(find(vec.begin(), vec.end(), followeeId) == vec.end())
            vec.push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            erase(following[followerId], followeeId);
    }
};
