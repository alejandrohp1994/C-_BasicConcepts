#include "library.h"

////////////////////////////////////////////////
// find the smallest element in an integer array
////////////////////////////////////////////////

void main()
{
	int const N = 5;
	int const x[N] = {3,2,5,1,9};
	int i = 0;
	int min = x[i];
	while (i<N)
	{
		if (x[i] < min) min= x[i];
		i = i + 1;
	}
	cout << "the smallest number is " << min << endl;
}

////////////////////////////////////////////////
// find the alphabetically first month
////////////////////////////////////////////////

void main()
{
	int const N = 12;
	string const month[N] = {"january","february","march","april","may",
                              "june","july","august","september","october",
                               "november","december"};
	int i = 0;
	string first = month[i];
	while (i<N)
	{
		if (month[i] < first) first= month[i];
		i = i + 1;
	}
	cout << "alphabetically first is " << first << endl;
}

/////////////////////////////////////////////////////
// DOT-PRODUCT OF TWO ARRAYS
////////////////////////////////////////////////////

int dot_product(int const x[], int const y[], int const size)
{
	int i = 0;
	int sum = 0;
	while (i<size)
	{
		sum = sum + x[i] * y[i];
		i = i + 1;
	}
	return(sum);
}

void main_dot_product()
{
	int const size = 3;
	int const x[size] = {2, 3, 4};
	int const y[size] = {2, 1, 2};
	int const result = dot_product(x,y,size);
	cout << "result: " << result << endl;
}

/////////////////////////////////////////////////////
// AVERAGE OF AN ARRAY
////////////////////////////////////////////////////

double average_of_array(int const x[], int const size)
{
	double sum = 0;
	int i = 0;
	while (i<size)
	{
		sum = sum + x[i];
		i++;
	}
	return(sum/size);
}

void main()
{
	int const size = 5;
	int const x[size] = {3,1,4,6,3};
	double const aver = average_of_array(x,size);
	cout << "the average is " << aver << endl;
}

///////////////////////////////////////////////////////////////
// try the following variations on array processing
//  - find the INDEX of the greatest member in an integer array
//  - find the month with the shortest name (use month[i].length())
//  - find the number of negative numbers in an integer array
//  - a function that returns true if even numbers outnumber odd 
//    numbers in an integer array (and returns false otherwise)
//  - for an int array, return the number of integers exceeding
//    a user-specified threshold
///////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// FIBONACCI SEQUENCE - USING A LOOP
////////////////////////////////////////////////////

void print_fibonacci(int const max)
{
	int A = 0, B = 1;
	int next;
	while (B < max)
	{
		cout << B << " ";
		next = A + B;
		A = B;
		B = next;
	}
	cout << "\n";
}

void main_loop()
{
	int const max = 30;
	print_fibonacci(max);
}

/////////////////////////////////////////////////////
// FIBONACCI SEQUENCE - USING RECURSION
////////////////////////////////////////////////////

void print_fib(int const A, int const B, int const N)
{
	if (N>0)
	{
		cout << B << " ";
		print_fib(B,A+B,N-1);
	}
}

void main()
{
	print_fib(0,1,10);
}

/////////////////////////////////////////////////////
// FIBONACCI SEQUENCE - USING AN ARRAY
////////////////////////////////////////////////////

void print_array(int const x[], int const size)
{
	int i = 0;
	while (i<size)
	{
		cout << x[i] << " ";
		i = i + 1;
	}
}

void main_array()
{
	int const max = 30;
	int x[20];
	x[0] = 1; x[1] = 1;
	int i = 1;
	while (x[i] < max)
	{
		i = i + 1;
		x[i] = x[i-1] + x[i-2];
	}
	print_array(x,i);
}


//////////////////////////////////////////////////////
// try the following variations on the FIBONACCI idea
//   - return the N-th number in the sequence
//   - sum up everything between the N-th nad M-th
//     numbers in the fibonacci sequence
//   - when the user submits an integer, return the
//     closest number from the fibonacci sequence
//////////////////////////////////////////////////////


