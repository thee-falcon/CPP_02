/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:16:58 by omakran           #+#    #+#             */
/*   Updated: 2024/02/11 16:22:17 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
    int                 _fixedPointNumerValue;
    static const int    _numberOfFractionalBits = 8;

    public:
    // constructors
    Fixed( void );
    Fixed ( const int num );
    Fixed ( const float num );
    // destructor
    ~Fixed( void );
    // copy constructor: hwa wahd special constructor likan ndiro beh wahd object jdid ka copy dyal wahd object f nafs l class.
    Fixed( const Fixed& other );
    // copy assignment operator.
    Fixed& operator=( const Fixed& other );
    // returns the raw value of the fixed-point value.
    int getRawBits( void ) const;
    // sets the raw value of the fixed-point number.
    void setRawBits( int const raw );
    // converts the fixed-point value to a floating-point value.
    float toFloat( void ) const;
    // converts the fixed-point value to an integer value.
    int toInt( void ) const;
    // Comparison operators
    bool operator>( const Fixed& other ) const;
    bool operator<( const Fixed& other ) const;
    bool operator>=( const Fixed& other ) const;
    bool operator<=( const Fixed& other ) const;
    bool operator==( const Fixed& other ) const;
    bool operator!=( const Fixed& other ) const;
    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
    // Increment and Decrement operators
    Fixed& operator++( void );    // pre-increment
    Fixed operator++( int );  // post-increment
    Fixed& operator--( void );    // pre-decrement
    Fixed operator--( int );  // post-decrement
    // Static member functions
    static Fixed& min( Fixed &a, Fixed &b );
    static const Fixed& min( const Fixed &a, const Fixed &b );
    static Fixed& max( Fixed &a, Fixed &b );
    static const Fixed& max( const Fixed &a, const Fixed &b );

};
    // overload of the insertion («) operator
    std::ostream& operator<<( std::ostream& os, const Fixed& fixed );

#endif