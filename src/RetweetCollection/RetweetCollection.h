#ifndef RETWEETCOLLECTION
#define RETWEETCOLLECTION

#include <set>

class Tweet;

class RetweetCollection
{
public:
    RetweetCollection();

    bool isEmpty() const;
    unsigned int size() const;

    void add(const Tweet& tweet);
    void remove(const Tweet& tweet);

private:
    std::set<Tweet> m_tweetSet;
};

#endif