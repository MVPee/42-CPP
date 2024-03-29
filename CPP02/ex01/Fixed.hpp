#ifndef FIXED_HPP
    #define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>

class Fixed
{
    private:
        int value;
        static const int bit = 8;
    public:
        Fixed(void);
        Fixed(const Fixed &fixed);
        Fixed(const int integer);
        Fixed(const float floating);
        ~Fixed(void);
        Fixed & operator = (const Fixed &fixed);

        int getBits(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

};

std::ostream& operator<<(std::ostream &os, Fixed const &fixed);

#endif