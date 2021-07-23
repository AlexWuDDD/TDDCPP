#include "Location.h"

std::ostream& operator<<(std::ostream& os, const Location& location)
{
    os << "(" << location.latitude() << "," << location.longitude() << ")";
    return os;
}

Location::Location()
    : latitude_(std::numeric_limits<double>::infinity())
    , longitude_(std::numeric_limits<double>::infinity())
{}

Location::Location(double latitude, double longitude)
    : latitude_(latitude), longitude_(longitude)
{}

double Location::latitude() const
{
    return latitude_;
}

double Location::longitude() const
{
    return longitude_;
}

bool Location::operator==(const Location& other) const
{
    return latitude_ == other.latitude_ && longitude_ == other.longitude_;
}

bool Location::operator!=(const Location& other) const
{
    return !(*this == other);
}

Location Location::go(double meters, double bearing) const
{
    //导向角度
    bearing = toRadians(bearing);
    double distance = { meters / RadiusOfEarthInMeters};
    double newLat{
        std::asin(std::sin(latitudeAsRadians())*std::cos(distance) +
                std::cos(latitudeAsRadians())*std::sin(distance)*std::cos(bearing))
    };
    double newLong = longitudeAsRadians();
    if(std::cos(latitudeAsRadians()) != 0){
        newLong = std::fmod(longitudeAsRadians() - asin(sin(bearing) * std::sin(distance) / std::cos(newLat)) + Pi, 2*Pi) - Pi;
    }

    return Location(toCoordinate(newLat), toCoordinate(newLong));
}

double Location::distanceInMeters(const Location& there) const {
   return RadiusOfEarthInMeters * haversineDistance(there);
}

bool Location::isUnknown() const {
   return latitude_ == std::numeric_limits<double>::infinity();
}

bool Location::isVeryCloseTo(const Location& there) const {
   return distanceInMeters(there) <= CloseMeters;
}

double Location::haversineDistance(Location there) const {
   double deltaLongitude { longitudeAsRadians() - there.longitudeAsRadians() };
   double deltaLatitude { latitudeAsRadians() - there.latitudeAsRadians() };

   double aHaversine { 
      pow(
         sin(deltaLatitude / 2.0), 2.0) + 
            cos(latitudeAsRadians()) * cos(there.latitudeAsRadians()) * pow(sin(deltaLongitude / 2), 
         2) };
   return 2 * atan2(sqrt(aHaversine), sqrt(1.0 - aHaversine));
}
