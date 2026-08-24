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


 // Revision (1)
 class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

    int time = 0;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        using T = tuple<int, int, int, int>;
        priority_queue<T> pq;

        if(tweets.count(userId) && !tweets[userId].empty()) {
            int idx = tweets[userId].size() -1;
            auto [t, id] = tweets[userId][idx];
            pq.push({t, id, userId, idx});
        }

        for (int followee : following[userId]) {
            if (!tweets.count(followee) || tweets[followee].empty())
                continue;
            
            int idx = tweets[followee].size() - 1;
            auto[t, id] = tweets[followee][idx];
            pq.push({t, id, followee, idx});
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto [t, tweetId, author, idx] = pq.top();
            pq.pop();

            feed.push_back(tweetId);

            if (idx > 0) {
                int nextIdx = idx - 1;
                auto [nextTime, nextTweetId] = tweets[author][nextIdx];

                pq.push({
                    nextTime,
                    nextTweetId,
                    author,
                    nextIdx
                });
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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