// https://leetcode.com/problems/design-twitter/

class Twitter {
public:
    int timeStamp = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;

    unordered_map<int, unordered_set<int>> follows;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        priority_queue<array<int,4>> pq;

        follows[userId].insert(userId);

        for (int uid : follows[userId]) {
            if (!tweets[uid].empty()) {
                int idx = tweets[uid].size() -1;
                auto [time, tweetId] = tweets[uid][idx];
                pq.push({time, tweetId, uid, idx});
            }
        }
        while (!pq.empty() && res.size() < 10) {
            auto [time, tweetId, uid, idx] = pq.top();
            pq.pop();

            res.push_back(tweetId);

            if (idx > 0) {
                auto [t, id] = tweets[uid][idx - 1];
                pq.push({t, id, uid, idx - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId)
            follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */