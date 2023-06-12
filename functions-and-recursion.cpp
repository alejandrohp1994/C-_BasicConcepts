#include "library.h"

////////////////////////////////////////////////////////
// conditions (IF) and relations: comparing two integers
////////////////////////////////////////////////////////

void main_compare()
{
	int const x = 4;
	int const y = 9;
	if (x > y) cout << "x is greater than y";
	else if (x < y) cout << "y is greater than x";	
	else cout << "they are the same";
	cout << endl;
}

/////////////////////////////////////////////////////////////////
// a function that accepts two integers as parameters, and returns
// the value of the smaller one
/////////////////////////////////////////////////////////////////

int smaller_integer(int const N, int const M)
{
	if (N<M) return(N);
	else return(M);
}

void main_smaller()
{
	int const x = 4;
	int const y = 9l
	int const smaller = smaller_integer(x,y);
	cout << smaller << endl;
}

////////////////////////////////////////////////////////
// An early instance of RECURSION:	:
// print a given message n times
////////////////////////////////////////////////////////

void print_messages(int const n)
{
	if (n>0)
	{
		cout << "I will do the homework alone" << endl;
		print_messages(n-1);
	}
}

void main_messages()
{
	int const n = 0;
	print_messages(n);
}

////////////////////////////////////////////////////////
// Another simple example of recursion:
// sum up all integers up to n
////////////////////////////////////////////////////////

int sums(int const n)
{
	if (n <= 0) return(0);
	else return(n + sums(n-1));
}

void main()
{
	int const n = 4;
	cout << "the sum is " << sums(n) << endl;
}

////////////////////////////////////////////////////////
// Minor modification of the previous function:
// sum up all integers between n and m (inclusive)
////////////////////////////////////////////////////////

int sums(int const n, int const m)
{
	if (n == m) return(n);
	else return(m + sums(n,m-1));
}

void main()
{
	int const n = 5;
	int const m = 6;
	cout << "the sum is " << sums(n,m) << endl;
}

////////////////////////////////////////////////////////
// Another variation on the "recursion" topic: product
// of all integers from 1 to n inclusive (n factorial)
////////////////////////////////////////////////////////

int product(int const n)
{
	if (n<=1) return(1);
	else return(n*product(n-1));
}

void main()
{
	int const n = 5;
	cout << "the product is " << product(n) << endl;
}

///////////////////////////////////////////////////////////////
// Minor modification of "print_messages"
// each line also contains the sequential number of the message
///////////////////////////////////////////////////////////////

void print_numbered_messages(int const N, int const MAX)
{
	if (N>0)
	{
		cout <<"message number " << MAX-N+1 << endl;
		print_numbered_messages(N-1,MAX);
	}
}

void main_numbered_messages()
{
	int const N = 5;
	print_numbered_messages(N,N);
}

////////////////////////////////////////////////////////
// print a dotted line
////////////////////////////////////////////////////////

void dotted_line(int const x, int const y, int const N, int const dist
{
	if (N>0)
	{
		draw_point(x,y)
		dotted_line(x+dist,y,N-1,dist);
	}
}

void main_dotted()
{
	make_window(500,400);
	set_pen_width(3);
	dotted_line(100,100,50,6);
}

////////////////////////////////////////////////////////
// a minor modification as a simple exercise:
// draw a row of squares (perhaps as a few windows to be
// used in a future picture of a building
// (you can recycle the draw_square() function from W01
////////////////////////////////////////////////////////








