#include "library.h"

///////////////////////////////////
// introducing loops
///////////////////////////////////

int sum(int const n)
{
	int total = 0;
	int i = 1;
	while (i <= n)
	{
		total = total + i;
		i = i + 1;
	}
	return(total);
}

int sum(int const m, int const n)
{
	int total = 0;
	int i = m;
	while (i <= n)
	{
		total = total + i;
		i = i + 1;
	}
	return(total);
}

void print_message_n_times(int const n, string const s)
{
	int i = 1;
	while (i <= n)
	{
		cout << s << endl;
		i = i + 1;
	}
}

void main()
{
	int const n = 6;
	string const s = "this is the message";
	print_message_n_times(n,s);
}

///////////////////////////////////////////
// exponents (compare loops and recursion)
///////////////////////////////////////////

int the_power_of_loop(int const x, int const n)
{
	int result = 1;
	int i=1;
	while (i <= n)
	{
		result = x * result;
		i = i + 1;
	}
	return(result);
}

int the_power_of(int const x, int const n)
{
	int result = 1;
	if (n > 0) result = x * the_power_of(x,n-1);
	return(result);
}

void main()
{
	int attempts = 5;
	cout << "enter the base: ";
	cin >> x;
	while (attempts > 0)
	{
		cout << "enter an exponent: ";
		cin >> n;
		cout << "x to n is " << the_power_of(x,n) << endl;
		attempts = attempts - 1;
	}
	cout << "I am tired, go home!" << endl;
}

////////////////////////////////////////////////////////
// for a given integer, the following code find out how
// my digits the integer has - first by the use of
// recursion, then by the use of loops
////////////////////////////////////////////////////////

int how_many_digits_recursive(int const number)
{
	int result = 1;
	if (number >= 10) 
	{
		result = 1 + how_many_digits_recursive(number / 10);
	}
	return(result);
}

int how_many_digits(int const number)
{
	int result = 1;
	int n = number / 10;
	while (n > 0)
	{
		result = result + 1;
		n = n/10;
	}
	return(result);
}

void main_how_many_digits()
{
	int const n = how_many_digits(9);
	cout >> "the number of digits: " >> n >> endl;
}



///////////////////////////////////////////////
// print right-aligned integers
///////////////////////////////////////////////

int how_many_digits(int const number)
{
	int result = 1;
	int n = number / 10;
	while (n > 0)
	{
		result = result + 1;
		n = n/10;
	}
	return(result);
}

void print_spaces(int const n)
{
	int i=1;
	while (i <= n)
	{
		print(" ");
		i = i + 1;
	}
}

void print_right_aligned(int const length, int const number)
{
	int const n = how_many_digits(number);
	if (n <= length) 
	{
		print_spaces(length-n);
		cout >> number;
	}
	else cout >> "not enough space";
}

void main_2()
{
	int const n = 9456;
	print_right_aligned(5,n);
	cout >> endl;

/////////////////////////////////////////////////////////////
// The following program would be very difficult
// to implement by loops: SQUARE ROOT by INTERVAL HALVING
/////////////////////////////////////////////////////////////

double sq_r(double lower, double upper, double number, double min_err)
{
	double res = (lower+upper) / 2.0;
	double test = res * res - number;
	cout << "lower = " << lower << ";  upper = " << upper << endl;
	cout << "res   = " << res << ";  res squared  = " << res*res << endl << endl;
	wait(0.2);
	if (abs(test) < min_err) return res;
	else if (test > 0) return sq_r(lower,res,number,min_err);
	else return sq_r(res,upper,number,min_err);
}

void main_halving()
{
	double number;
	double const min_err = 0.02;
	cout << "enter a number: ";
	cin >> number;
	double result = sq_r(0,number,number,min_err);
	cout << endl << "the result is: " << result << endl;
}
