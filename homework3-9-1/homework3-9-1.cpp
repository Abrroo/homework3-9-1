#include <iostream>
#include <numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	int multiplyFirstCross(Fraction other) { return numerator_ * other.denominator_; }
	int multiplySecondCross(Fraction other) { return other.numerator_ * denominator_; }

	bool operator==(Fraction other) { return numerator_ == other.numerator_ && denominator_ == other.denominator_; }
	bool operator!=(Fraction other) { return !(numerator_ == other.numerator_ && denominator_ == other.denominator_); }
	bool operator<(Fraction other) { return multiplyFirstCross(other) < multiplySecondCross(other); }
	bool operator>(Fraction other) { return multiplyFirstCross(other) > multiplySecondCross(other); }
	bool operator<=(Fraction other) { return !(multiplyFirstCross(other) > multiplySecondCross(other)); }
	bool operator>=(Fraction other) { return !(multiplyFirstCross(other) < multiplySecondCross(other)); }

	Fraction divided()
	{
		int divisor = std::gcd(numerator_,denominator_);
		numerator_ = numerator_ / divisor;
		denominator_ = denominator_ / divisor;
		return *this;
	}


};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(8, 6);

	std::cout << "f1" << ((f1.divided() == f2.divided()) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1.divided() != f2.divided()) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1.divided() < f2.divided()) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1.divided() > f2.divided()) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1.divided() <= f2.divided()) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1.divided() >= f2.divided()) ? " >= " : " not >= ") << "f2" << '\n';
	
	return 0;
}