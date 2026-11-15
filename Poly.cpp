#include "Poly.h"
#include <iostream>
#include <map>
#include <cmath>

Poly::Poly()
{

}

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

Poly operator-(const Poly& p1, const Poly& p2)
{
    Poly n(p1);
    return n -= p2; 
}

Poly operator-(const Poly& p)
{
    Poly n(p);
    return 0-n;
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