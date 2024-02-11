/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:00:49 by omakran           #+#    #+#             */
/*   Updated: 2024/02/11 16:23:07 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
    int                 _fixedPointNumerValue;
    static const int    _numberOfFractionalBits = 8;

    public:
    // constructors
    Fixed( void );
    Fixed (const int num);
    Fixed (const float num);
    // destructor
    ~Fixed();
    // copy constructor: hwa wahd special constructor likan ndiro beh wahd object jdid ka copy dyal wahd object f nafs l class.
    Fixed(const Fixed& other);
    // copy assignment operator.
    Fixed& operator=(const Fixed& other);
    // returns the raw value of the fixed-point value.
    int getRawBits( void ) const;
    // sets the raw value of the fixed-point number.
    void setRawBits( int const raw );
    // converts the fixed-point value to a floating-point value.
    float toFloat( void ) const;
    // converts the fixed-point value to an integer value.
    int toInt( void ) const;
};
    //  overload of the insertion («) operator
    std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif