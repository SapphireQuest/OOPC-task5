#include "Poly.h"
#include <iostream>
#include <map>
#include <cmath>


Poly::Poly(double value)
{
    if(value == 0)
    {
        return;
    }
    coeffs[0] = value;
}


void Poly::erase_helper()
{
    auto i = this->coeffs.begin();
    while(i != this->coeffs.end())
    {
        double coefficient = i->second;
        if(coefficient == 0.0)
        {
            i = this->coeffs.erase(i);
        }
        else
        {
            i++;
        }
    }
}


double& Poly::operator[](int index)
{
    return coeffs[index];
}

double Poly::operator[](int index) const
{
    auto readValue = coeffs.find(index);
    if(readValue != coeffs.end())
    {
        return readValue->second;
    }
    return 0.0;
}

Poly& Poly::operator+=(const Poly& p)
{
    for(const auto &c : p.coeffs)
    {
        int power = c.first;
        double coefficient = c.second;
        this->coeffs[power] += coefficient;
    }
    erase_helper();
    return *this;
}

Poly operator+(const Poly& p1, const Poly& p2)
{
    Poly n(p1);
    return n += p2; 
}

double Poly::operator()(double point) const
{
    double value = 0;
    for(const auto &c : this->coeffs)
    {
        int power = c.first;
        double coefficient = c.second;
        
        value += coefficient * (std::pow(point, power));
    }
    return value;
}


Poly& Poly::operator-=(const Poly& p)
{
    for(const auto &c : p.coeffs)
    {
        int power = c.first;
        double coefficient = c.second;
        this->coeffs[power] -= coefficient;
    }
    erase_helper();
    return *this;
}


Poly& Poly::operator*=(const Poly& p)
{
    std::map<int,double,std::greater<int>> result;
    for(const auto &c1 : this->coeffs)
    {
        int power1 = c1.first;
        double coefficient1 = c1.second;
        for(const auto &c2 : p.coeffs)
        {
            int power2 = c2.first;
            double coefficient2 = c2.second;
            
            int newPower = power1 + power2;
            double newCoefficient = coefficient1 * coefficient2;
            result[newPower] += newCoefficient;
        }   
    }
    this->coeffs = result;
    erase_helper();
    return *this;
}

Poly operator-(const Poly& p1, const Poly& p2)
{
    Poly n(p1);
    return n -= p2; 
}

Poly operator-(const Poly& p)
{
    return 0-p;
}

Poly operator*(const Poly& p1, const Poly& p2)
{
    Poly n(p1);
    return n *= p2; 
}


std::ostream& operator<<(std::ostream& os, const Poly& p)
{
    bool first = true;
    for(const auto &c : p.coeffs)
    {
        int power = c.first;
        double coefficient = c.second;
        if(coefficient == 0)
        {
            continue;
        }

        if(first)
        {
            if(coefficient < 0)
            {
                os << "-";
            }
        }
        else
        {
            if(coefficient < 0)
            {
                os << " - ";
            }
            else
            {
                os << " + ";
            }
        }

        double absValue = std::fabs(coefficient);
        if(absValue != 1 || power == 0)
        {
            os << absValue;
        }

        if(power == 1)
        {
            os << "x";
        }
        else if(power > 1)
        {
            os << "x^" << power;
        }

        first = false;
    }

    if(first)
    {
        os << "0";
    }
    return os;
}