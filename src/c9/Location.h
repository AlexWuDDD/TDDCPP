#ifndef LOCATION_H
#define LOCATION_H

#include <limits>
#include <cmath>
#include <ostream>

/*
tan(PI/4)=1 
PI=4*arctan(1)
arctan()在C语言里表示为atan() 即pi=4.0*atan(1.0) 这里保证了精度
*/
const double Pi{4.0 * std::atan(1.0)};
const double ToRadiansConversionFactor{Pi / 180.0};
//地球半径
const double RadiusOfEarthInMeters{6372000};
//地球的周长大概40000公里左右，在赤道上,经度每差1度,实际距离为111千米左右。
const double MetersPerDegreeAtEquator{111111};

const double North{0};
const double West{90};
const double South{180};
const double East{270};
const double CloseMeters{3};

class Location
{
public:
    Location();
    Location(double latitude, double longitude);

    inline double toRadians(double degrees) const
    {
        return degrees * ToRadiansConversionFactor;
    }

    inline double toCoordinate(double radians) const
    {
        return radians * (180.0 / Pi);
    }

    inline double latitudeAsRadians() const
    {
        return toRadians(latitude_);
    }

    inline double longitudeAsRadians() const
    {
        return toRadians(longitude_);
    }

    double latitude() const;
    double longitude() const;

    bool operator==(const Location& that) const;;
    bool operator!=(const Location& that) const;

    Location go(double meter, double bearing) const;
    double distanceInMeters(const Location& that) const;
    bool isUnknown() const;
    bool isVeryCloseTo(const Location& that) const;

private:
    double latitude_;
    double longitude_;

    double haversineDistance(Location there)const;
};

std::ostream& operator<<(std::ostream& os, const Location& location);

#endif