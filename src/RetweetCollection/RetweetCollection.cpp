#include "RetweetCollection.h"
#include "../Tweet/Tweet.h"


RetweetCollection::RetweetCollection()
{
    m_tweetSet.clear();
}

bool RetweetCollection::isEmpty() const
{
    return m_tweetSet.empty();
}

unsigned int RetweetCollection::size() const
{
    return m_tweetSet.size();
}

void RetweetCollection::add(const Tweet& tweet)
{
    m_tweetSet.insert(tweet);
}

void RetweetCollection::remove(const Tweet& tweet)
{
    auto iter = m_tweetSet.find(tweet);
    if(iter != m_tweetSet.end()){
        m_tweetSet.erase(iter);
    }
}