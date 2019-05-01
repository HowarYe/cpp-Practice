//============================================================================
// Name        : test1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Fraction {
	public:
	const static Fraction half;
	const static Fraction oneThird;
	const static Fraction quarter;
	const static Fraction oneFifth;
	Fraction(int n, int d);
	Fraction add(Fraction a);
	Fraction sub(Fraction a);
	Fraction mult(Fraction a);
	Fraction divide(Fraction a);
	void displace() const;
	int comp(Fraction a) const;
	inline int getNumerator() const {return numerator;}
	inline int getDenominator() const {return denominator;}
	private:
	int numerator, denominator;
	int get_greatest_common_divisor(int n, int d);
};

const Fraction Fraction::half(1,2);
const Fraction Fraction::oneThird(1,3);
const Fraction Fraction::quarter(1,4);
const Fraction Fraction::oneFifth(1,5);

Fraction::Fraction(int n = 0, int d = 1): numerator(n), denominator(d){}

int Fraction::get_greatest_common_divisor(int n, int d){
    int temp;
    int a = n;
    int b = d;
    if(a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    while(b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

Fraction Fraction::add(Fraction a){
	int n, thisN, newD, newN, gcd;
	n = a.numerator * this->denominator;
	newD = a.denominator * this->denominator;
	thisN = this->numerator * a.denominator;
	int c = this->comp(a);
	if (c == 0){
		Fraction newF(a.numerator*2,a.denominator);
		return newF;
	}
	else{
		newN = thisN + n;
		gcd = get_greatest_common_divisor(newN, newD);
		newN /= gcd;
		newD /= gcd;
		Fraction newF(newN, newD);
		return newF;
	}
}

Fraction Fraction::sub(Fraction a) {
	int n, thisN, newD, newN, gcd;
	n = a.numerator * this->denominator;
	newD = a.denominator * this->denominator;
	thisN = this->numerator * a.denominator;
	int c = this->comp(a);
	if (c == 0){
		Fraction newF;
		return newF;
	}
	else{
		newN = abs(thisN - n);
		gcd = get_greatest_common_divisor(newN, newD);
		newN /= gcd;
		newD /= gcd;
		Fraction newF(newN, newD);
		return newF;
	}
}

Fraction Fraction::mult(Fraction a){
	int newD, newN, gcd;
	newN = a.numerator * this->numerator;
	newD = a.denominator * this->denominator;
	gcd = get_greatest_common_divisor(newN, newD);
	newN /= gcd;
	newD /= gcd;
	Fraction newF(newN, newD);
	return newF;
}

Fraction Fraction::divide(Fraction a){
	int newD, newN, gcd;
	newD = a.denominator * this->numerator;
	newN = a.numerator * this->denominator;
	gcd = get_greatest_common_divisor(newN, newD);
	newN /= gcd;
	newD /= gcd;
	Fraction newF(newN, newD);
	return newF;
}

int Fraction::comp(Fraction a) const{
	int n, thisN;
	n = a.numerator * this->denominator;
	thisN = this->numerator * a.denominator;
	if(n > thisN)
		return 1;
	else if(n < thisN)
		return -1;
	else
		return 0;
}

void Fraction::displace() const{
	cout << "fraction is: " << numerator << "/" << denominator << endl;
}

int main() {
	cout << "half in ";
	Fraction::half.displace();
	Fraction zero;
	zero.displace();
	Fraction a(2,5);
	Fraction b(3,7);
	Fraction add = a.add(b);
	Fraction sub = a.sub(b);
	Fraction mul = a.mult(b);
	Fraction div = a.divide(b);
	a.displace();
	b.displace();
	cout << "after adding, ";
	add.displace();
	cout << "after sub, ";
	sub.displace();
	cout << "after mult, ";
	mul.displace();
	cout << "after div, ";
	div.displace();
	return 0;
}
