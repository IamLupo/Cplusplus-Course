#ifndef MYCUSTOMLIB_MATH_H
#define MYCUSTOMLIB_MATH_H

namespace MyCustomLib
{
	namespace Math
	{
		long long gcd(long long a, long long b);
		long long gcdr(long long a, long long b);
		
		long long phi(long long n);
		
		long long factorial(long long n);
		
		long long binomial_coefficient(unsigned long n, unsigned long k);
	} // Math
} // MyCustomLib

#endif // MYCUSTOMLIB_MATH_H
