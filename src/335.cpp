#include <bits/stdc++.h>
using namespace std;


class Twitter {
public:
    typedef pair<int, int> PII;

    map<int, vector<int>> follows; //关注
    map<int, vector<int>> followings; //粉丝
    map<int, vector<PII>> twitters; //每个人自己的twitter列表
    int t = 0;

    /** Initialize your data structure here. */
    Twitter() {

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        PII tw = {t, tweetId};
        twitters[userId].push_back(tw);
        t++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> see_twitter;
        vector<PII> res;
        res = twitters[userId];
        //关注列表
        vector<int> follow = follows[userId];
        for(auto x: follow){
            vector<PII> tmp = twitters[x];
            res.insert(res.end(), tmp.begin(), tmp.end());
        }
        sort(res.begin(), res.end());

        // cout << "=====" << endl;
        // for(auto x: res){
        //     cout << x.first << " " << x.second << endl;
        // }
        
        int n = res.size(), k = 0;
        while(n--){
            see_twitter.push_back(res[n].second);
            k ++;
            if(k == 10) break;
        }
        return see_twitter;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        auto tmp_follow_list = follows[followerId];
        if(find(tmp_follow_list.begin(), tmp_follow_list.end(), followeeId) != tmp_follow_list.end()) return;

        follows[followerId].push_back(followeeId);
        // followings[followeeId].push_back(followerId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        //删follower的关注列表
        auto iter = find(follows[followerId].begin(), follows[followerId].end(), followeeId);
        if(iter != follows[followerId].end()){
            follows[followerId].erase(iter);
        }
        // //删followeeId的粉丝列表
        // iter = find(followings[followeeId].begin(), followings[followeeId].end(), followerId);
        // if(iter != followings[followeeId].end()){
        //     followings[followeeId].erase(iter);
        // }
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