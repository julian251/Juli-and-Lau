#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Twitter
{
private:
    struct Tweet
    {
        int tweetId;
        int time;
        Tweet(int id, int t) : tweetId(id), time(t) {}
    };

    unordered_map<int, unordered_set<int>> followers; // Usuarios que sigue cada usuario
    unordered_map<int, vector<Tweet>> tweets;         // Tweets de cada usuario
    int time = 0;                                     // Marca de tiempo para los tweets

public:
    Twitter()
    {
        // Constructor
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back(Tweet(tweetId, time++));
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> pq; // Cola de prioridad para ordenar por tiempo

        // Agregar los tweets del propio usuario
        for (const Tweet &tweet : tweets[userId])
        {
            pq.push({tweet.time, tweet.tweetId});
        }

        // Agregar los tweets de los usuarios que sigue
        for (int followeeId : followers[userId])
        {
            for (const Tweet &tweet : tweets[followeeId])
            {
                pq.push({tweet.time, tweet.tweetId});
            }
        }

        // Obtener los 10 tweets más recientes
        vector<int> feed;
        while (!pq.empty() && feed.size() < 10)
        {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return; // No se puede seguir a sí mismo
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return; // No se puede dejar de seguir a sí mismo
        followers[followerId].erase(followeeId);
    }
};

int main()
{
    Twitter twitter;

    // Usuario 1 publica un tweet
    twitter.postTweet(1, 5);

    // Usuario 1 obtiene su feed de noticias
    vector<int> feed = twitter.getNewsFeed(1);
    cout << "Feed de usuario 1: ";
    for (int tweetId : feed)
    {
        cout << tweetId << " ";
    }
    cout << endl;

    // Usuario 1 sigue al usuario 2
    twitter.follow(1, 2);

    // Usuario 2 publica un tweet
    twitter.postTweet(2, 6);

    // Usuario 1 obtiene su feed de noticias
    feed = twitter.getNewsFeed(1);
    cout << "Feed de usuario 1 después de seguir al usuario 2: ";
    for (int tweetId : feed)
    {
        cout << tweetId << " ";
    }
    cout << endl;

    // Usuario 1 deja de seguir al usuario 2
    twitter.unfollow(1, 2);

    // Usuario 1 obtiene su feed de noticias
    feed = twitter.getNewsFeed(1);
    cout << "Feed de usuario 1 después de dejar de seguir al usuario 2: ";
    for (int tweetId : feed)
    {
        cout << tweetId << " ";
    }
    cout << endl;

    return 0;
}