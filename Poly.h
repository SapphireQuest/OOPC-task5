#pragma once
#include <iostream>
#include <map>


class Poly
{
    private:
        std::map<int,double,std::greater<int>> coeffs;
        void erase_helper();
    public:
        Poly(double value = 0);
       
        double& operator[](int index);
        double operator[](int index) const;
        double operator()(double point) const;
        friend std::ostream& operator<<(std::ostream& os, const Poly& p);
        Poly& operator+=(const Poly& p); 
        Poly& operator-=(const Poly& p); 
        Poly& operator*=(const Poly& p); 
};

Poly operator+(const Poly& p1, const Poly& p2);
Poly operator-(const Poly& p1, const Poly& p2);
Poly operator-(const Poly& p);
Poly operator*(const Poly& p1, const Poly& p2);
