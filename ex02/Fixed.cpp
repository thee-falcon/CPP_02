/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:16:54 by omakran           #+#    #+#             */
/*   Updated: 2024/02/11 11:16:38 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointNumerValue(0) {}
Fixed::Fixed( const int num ) : _fixedPointNumerValue(num << _numberOfFractionalBits) {}
Fixed::Fixed( const float num ) : _fixedPointNumerValue(static_cast<int>(roundf(num * (1 << _numberOfFractionalBits)))) {}
Fixed::Fixed( const Fixed& other )
{
    this->setRawBits(other.getRawBits());
}
Fixed::~Fixed( void ) {}

Fixed& Fixed::operator=( const Fixed& other )
{
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

std::ostream& operator<<( std::ostream& os, const Fixed& fixed )
{
    os << fixed.toFloat();
    return (os);
}

// Comparison operators
bool    Fixed::operator>( const Fixed& other ) const {
    return (this->getRawBits() > other.getRawBits());
}

bool    Fixed::operator<( const Fixed& other ) const {
    return (this->getRawBits() < other.getRawBits());
}

bool    Fixed::operator>=( const Fixed& other ) const {
    return (this->getRawBits() >= other.getRawBits());
}

bool    Fixed::operator<=( const Fixed& other ) const {
    return (this->getRawBits() <= other.getRawBits());
}

bool    Fixed::operator==( const Fixed& other ) const {
    return (this->getRawBits() == other.getRawBits());
}

bool    Fixed::operator!=( const Fixed& other ) const {
    return (this->getRawBits() != other.getRawBits());
}

// Arithmetic operators
Fixed Fixed::operator+( const Fixed& other ) const {
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-( const Fixed& other ) const {
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*( const Fixed& other ) const {
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/( const Fixed& other ) const {
    return (Fixed(this->toFloat() / other.toFloat()));
}

// Increment and Decrement operators
Fixed& Fixed::operator++( void ) {
    this->_fixedPointNumerValue++;
    return (*this);
}

Fixed Fixed::operator++( int ) {
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed& Fixed::operator--( void ) {
    this->_fixedPointNumerValue--;
    return (*this);
}

Fixed Fixed::operator--( int ) {
    Fixed temp(*this);
    --(*this);
    return (temp);
}

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    return ((a < b) ? a : b);
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    return ((a < b) ? a : b);
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    return ((a > b) ? a : b);
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    return ((a > b) ? a : b);
}