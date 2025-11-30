#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed
{
private:
    int                 fixedPointValue;
    static const int    fractionalBits = 8;
public:
    Fixed();
    Fixed(const int Value);
    Fixed(const float Value);
    ~Fixed();


    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif