#include "GeoServer.h"

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

std::vector<User> GeoServer::usersInBox(const std::string& user, double widthInMeters, double heightInMeters) const
{
    auto location = locations_.find(user)->second;
    Area box {location, widthInMeters, heightInMeters};

    std::vector<User> users;
    for(auto& each : locations_){
        if(isDifferentUserInBounds(each, user,  box))
            users.emplace_back(User{each.first, each.second});
    }
    return users;
}