class Twitter {
private:
    struct Tweet {
        int time;
        int id;
    };

    struct HeapEntry {
        int time;
        int tweetId;
        int userId;
        int index;

        bool operator<(const HeapEntry& other) const {
            return time < other.time;
        }
    };

    int timestamp = 0;

    std::unordered_map<int, std::vector<Tweet>> tweets;
    std::unordered_map<int, std::unordered_set<int>> following;

public:
    Twitter() = default;

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<HeapEntry> heap;

        auto addLatestTweet = [&](int id) {
            auto& userTweets = tweets[id];

            if (userTweets.empty()) {
                return;
            }

            int index = static_cast<int>(userTweets.size()) - 1;
            const auto& tweet = userTweets[index];

            heap.push({
                tweet.time,
                tweet.id,
                id,
                index
            });
        };

        // Eigene Tweets
        addLatestTweet(userId);

        // Tweets aller Followees
        for (int followeeId : following[userId]) {
            addLatestTweet(followeeId);
        }

        std::vector<int> feed;

        while (!heap.empty() && feed.size() < 10) {
            auto current = heap.top();
            heap.pop();

            feed.push_back(current.tweetId);

            // Nächstälteren Tweet desselben Users hinzufügen
            int nextIndex = current.index - 1;

            if (nextIndex >= 0) {
                const auto& nextTweet =
                    tweets[current.userId][nextIndex];

                heap.push({
                    nextTweet.time,
                    nextTweet.id,
                    current.userId,
                    nextIndex
                });
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};