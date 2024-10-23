#include "Fixed.hpp"

Fixed::Fixed() 
{
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
    this->value = (val << fract);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
    this->value = roundf(val * (1 << fract));
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

bool Fixed::operator>(const Fixed &other)
{
    return (this->value > other.value);
}

bool Fixed::operator<(const Fixed &other)
{
    return (this->value < other.value);
}


bool Fixed::operator>=(const Fixed &other)
{
    return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed &other)
{
    return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed &other)
{
    return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other)
{
    return (this->value != other.value);
}

int Fixed::operator+(const Fixed &other)
{
    return (this->value + other.value);
}


int Fixed::operator*(const Fixed &other)
{
    return (this->value * other.value);
}

int Fixed::operator-(const Fixed &other)
{
    return (this->value - other.value);
}

int Fixed::operator/(const Fixed &other)
{
    return (this->value / other.value);
}

Fixed &Fixed::operator++()
{
    value++;
    return (*this);

}

Fixed Fixed::operator++(int)
{
    
    Fixed copie(*this);
    this->value++;
    return(copie);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
    return (f1.value < f2.value ? f1 : f2);
}
 Fixed& Fixed::min( Fixed &f1,  Fixed &f2)
{
    return (f1.value < f2.value ? f1 : f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
    return (f1.value > f2.value ? f1 : f2);
}
Fixed& Fixed::max(Fixed &f1,  Fixed &f2)
{
    return (f1.value > f2.value ? f1 : f2);
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

float Fixed::toFloat(void) const {
    return (float)((this->value) / (1 << fract));
}

int Fixed::toInt(void) const {
    return (this->value >> fract);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

