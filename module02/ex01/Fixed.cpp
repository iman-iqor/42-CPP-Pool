#include "Fixed.hpp"  

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}  


Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called " << std::endl;
    this->fixedPointValue = value << fractionalBits; //shift left to convert int to fixed-point
}


//roundf(...) returns a float.
//fixedPointValue is an int.
//the compiler will implicitly convert the float to an int anyway.
//roundf to round the float value to the nearest integer
//for example, 42.42 * 256 = 10859.52, roundf gives 10860
Fixed::Fixed(const float Value)
{
    std::cout << "Float constructor called " << std::endl;
    this->fixedPointValue = (roundf(Value * (1 << fractionalBits))); //convert float to fixed-point
}



float Fixed::toFloat(void) const
{
    return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->fixedPointValue >> fractionalBits;
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


//overload the insertion operator to output the fixed-point number as a float
//this allows using std::cout << fixedObject; to print the float representation
//return the output stream to allow chaining of output operations like std::cout << a << b;
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;;
}   