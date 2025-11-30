#include "Fixed.hpp"  

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}  

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//copy constructor to create a new object as a copy of an existing object
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = other.fixedPointValue;
}

//copy assignment operator to assign values from one existing object to another existing object
//return type Fixed& to allow chained assignments like a = b = c;
//also, check for self-assignment to avoid unnecessary work
//return a reference to the current object (*this) after assignment 
Fixed &Fixed::operator=(const Fixed &other)             
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedPointValue = other.fixedPointValue;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}