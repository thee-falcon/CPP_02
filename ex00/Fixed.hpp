/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:25:27 by omakran           #+#    #+#             */
/*   Updated: 2024/02/08 21:18:55 by omakran          ###   ########.fr       */
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
    // constructor_
    Fixed();
    // destructor
    ~Fixed();
    // copy destructor: hwa wahd special constructor likan ndiro beh wahd object jdid ka copy dyal wahd object f nafs l class.
    Fixed(const Fixed& other);
    // copy assignment operator.
    Fixed& operator=(const Fixed& other);
    // returns the raw value of the fixed-point value.
    int getRawBits( void ) const;
    // sets the raw value of the fixed-point number.
    void setRawBits( int const raw );
};
# endif