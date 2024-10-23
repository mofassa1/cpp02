#include "Fixed.hpp"

Fixed::Fixed() 
{
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
    this->value = val << fract;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{

    // val = 2.74            0 000001   0000000000010000000010
    // 2.74   *  256  => 701.44  -> 701
    this->value = roundf(val * (1 << fract)); // IEEE 756  -> this->value = 701
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

float Fixed::toFloat(void) const {
    return ((this->value) / (1 << fract));
}

int Fixed::toInt(void) const {
    return (this->value >> fract);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

