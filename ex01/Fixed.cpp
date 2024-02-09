/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:00:48 by omakran           #+#    #+#             */
/*   Updated: 2024/02/09 19:00:58 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) :_fixedPointNumerValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ) : _fixedPointNumerValue(num << _numberOfFractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) : _fixedPointNumerValue(static_cast<int>(roundf(num * (1 << _numberOfFractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(other.getRawBits());
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedPointNumerValue = other.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    return (this->_fixedPointNumerValue);
}

void    Fixed::setRawBits( int const raw )
{
    this->_fixedPointNumerValue = raw;
}

float   Fixed::toFloat( void ) const
{
    return (static_cast<float>(_fixedPointNumerValue) / (1 << _numberOfFractionalBits));
}

int Fixed::toInt( void ) const
{
    return (_fixedPointNumerValue >> _numberOfFractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}