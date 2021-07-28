#include "GeoServer.h"
#include "Work.h"

void GeoServer::track(const std::string& user)
{
    locations_[user] = Location();
}

void GeoServer::stopTracking(const std::string& user)
{
    locations_.erase(user);
}

void GeoServer::updateLocation(const std::string& user, const Location& location)
{
    locations_[user] = location;
}

bool GeoServer::isTracking(const std::string& user) const
{
    return find(user) != locations_.end();
}

Location GeoServer::locationOf(const std::string& user) const
{
    if(!isTracking(user)) return Location{};
    return find(user)->second;
}

std::unordered_map<std::string, Location>::const_iterator GeoServer::find(const std::string& user) const
{
    return locations_.find(user);
}

bool GeoServer::isDifferentUserInBounds(const std::pair<std::string, Location>&each, const std::string& user, const Area& box) const
{
    if(each.first == user) return false;
    return box.inBounds(each.second);
}

void GeoServer::usersInBox(
    const std::string& user, double widthInMeters, double heightInMeters,
    GeoServerListener* listener) const
{
    auto location = locations_.find(user)->second;
    Area box {location, widthInMeters, heightInMeters};

    for(auto& each : locations_){
        Work work{[&]{
            if(isDifferentUserInBounds(each, user,  box))
                listener->updated(User{each.first, each.second});
        }};
        pool_->add(work);
    }
}

void GeoServer::userThreadPool(std::shared_ptr<ThreadPool> pool)
{
    pool_ = pool;
}