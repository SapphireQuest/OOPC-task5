#pragma once
#include <iostream>
#include <map>


class Poly
{
    private:
        std::map<int,double,std::greater<int>> coeffs;

    public:
        Poly();
        Poly(double value);
       
        double& operator[](int index);
        double operator[](int index) const;
        friend std::ostream& operator<<(std::ostream& os, const Poly& p);
};