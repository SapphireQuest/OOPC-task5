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





std::ostream& operator<<(std::ostream& os, const Poly& p)
{
    bool first = true;
    for(auto c : p.coeffs)
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