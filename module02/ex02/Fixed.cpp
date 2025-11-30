#include "Fixed.hpp"  

Fixed::Fixed() : fixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}  


Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called " << std::endl;
    this->fixedPointValue = value << fractionalBits; //shift left to convert int to fixed-point
}


//roundf(...) returns a float.
//fixedPointValue is an int.
//the compiler will implicitly convert the float to an int anyway.
//roundf to round the float value to the nearest integer
//for example, 42.42 * 256 = 10859.52, roundf gives 10860
Fixed::Fixed(const float Value)
{
    // std::cout << "Float constructor called " << std::endl;
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
    // std::cout << "Destructor called" << std::endl;
}

//copy constructor to create a new object as a copy of an existing object
Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->fixedPointValue = other.fixedPointValue;
}

//copy assignment operator to assign values from one existing object to another existing object
//return type Fixed& to allow chained assignments like a = b = c;
//also, check for self-assignment to avoid unnecessary work
//return a reference to the current object (*this) after assignment 
Fixed &Fixed::operator=(const Fixed &other)             
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedPointValue = other.fixedPointValue;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
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


//arithmetic operators

//convert both to float because internaly they are stored as fixed-point
//perform the arithmetic operation on the float values
//return a new Fixed object constructed from the result

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
} 

//increment and decrement operators
// Make a copy (temp(*this)).
// Increment the current object.
// Return the copy (the old value).
//postfix increment: create a copy of the current object, increment the value, return the copy
// parameter int It’s just a dummy parameter used only to distinguish postfix from prefix.
Fixed Fixed::operator++(int)
{
    Fixed temp(*this); //create a copy
    this->fixedPointValue++;//increment the value of the current object that called the operator not the copy
    return temp; //return the copy
}

//prefix increment: increment the value and return the current object by reference
Fixed &Fixed::operator++()
{
    this->fixedPointValue++;
    return *this;
} 

//prefix decrement: decrement the value and return the current object by reference
Fixed &Fixed::operator--()
{
    this->fixedPointValue--;
    return *this;
}      
//postfix decrement: create a copy of the current object, decrement the value, return the copy
Fixed Fixed::operator--(int)
{
    Fixed temp(*this); //create a copy
    this->fixedPointValue--;
    return temp; //return the copy
}




//comparison operators


//this is similar to operator >
bool Fixed::operator>(const Fixed &other) const
{
    return this->fixedPointValue > other.fixedPointValue;
}

//this is similar to operator <
bool Fixed::operator<(const Fixed &other) const
{
    return this->fixedPointValue < other.fixedPointValue;
}
bool Fixed::operator>=(const Fixed &other) const
{
    return this->fixedPointValue >= other.fixedPointValue;
}
bool Fixed::operator<=(const Fixed &other) const
{
    return this->fixedPointValue <= other.fixedPointValue;
}

//static member functions for min and max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if(a < b)
        return a;
    return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a < b)
        return a;
    return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if(a > b)
        return a;
    return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if(a > b)
        return a;
    return b;
}