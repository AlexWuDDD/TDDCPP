#ifndef TWEET_H
#define TWEET_H

#include <string>

class Tweet
{
public:
    Tweet(const std::string& msg, const std::string& user);
    ~Tweet();

    bool operator<(const Tweet& tweet) const{
        return tweet.msg != msg || tweet.user != user;
    }

private:
    std::string msg;
    std::string user;
};



#endif