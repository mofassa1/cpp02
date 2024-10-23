#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int fract = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        ~Fixed();

        Fixed& operator=(const Fixed& other);
        bool operator>(const Fixed &other);
        bool operator<(const Fixed &other);
        bool operator>=(const Fixed &other);
        bool operator<=(const Fixed &other);
        bool operator==(const Fixed &other);
        bool operator!=(const Fixed &other);

        int operator+(const Fixed &other);
        int operator*(const Fixed &other);
        int operator-(const Fixed &other);
        int operator/(const Fixed &other);

        Fixed& operator++();
        Fixed operator++(int);

        static const Fixed& min(const Fixed &f1, const Fixed &f2);
        static Fixed& min(Fixed &f1, Fixed &f2);
        static const Fixed& max(const Fixed &f1, const Fixed &f2);
        static Fixed& max(Fixed &f1, Fixed &f2);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

};

        std::ostream& operator<<(std::ostream& os, const Fixed &fixed);



#endif