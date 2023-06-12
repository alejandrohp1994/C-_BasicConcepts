#include "library.h"

///////////////////////////////////
// primes using Dr.Murrell's approach
///////////////////////////////////

bool is_prime(const int N)
{
	int divisor = 2;
	while (divisor < N/2)
	{
		if (N%divisor==0) return(false);
		divisor++;
	}
	return(true);
}

void print_so_many_primes(int const num_wanted)
{
	int num_printed=0, candidate=2;
	while (num_printed<num_wanted)
	{
		if (is_prime(candidate))
		{
			cout << candidate << endl;
			num_printed++;
		}
		candidate++;
	}
}

void main()
{
	print_so_many_primes(30);
}	

//////////////////////////////////
// sieve of eratosthenes
//////////////////////////////////

void sieve(bool prime_numbers[], int const size)
{
	int i;
	prime_numbers[0] = false;
	prime_numbers[1] = false;
	for (int num=2; num <size/2; num++)
	{
		i = 2;
		while (i*num < size)
		{
			prime_numbers[i*num] = false;
			i++;
		}
	}
}

void print_primes(bool prime_numbers[], int const size)
{
	for (int i=0; i<size; i++)
		if (prime_numbers[i]) cout << i << endl;
}

void main()
{
	int const size = 100;
	bool prime_numbers[size];
	for (int i=0;i<size;i++) prime_numbers[i] = true;
	sieve(prime_numbers,size);
	print_primes(prime_numbers,size);
}


///////////////////////////////////
// sorting integer arrays
///////////////////////////////////

void swap(int & x, int & y)
{
	int tmp = x;
	x = y;
	y = tmp; }

void main_sorting_integer_arrays()
{
	int i,j,low;
	int const length = 5;
	int x[length] = {32,22,19,8,-18};
	for (i=0;i<length-1; i++)
	{
		low = i;
		for (j=i+1;j<length;j++)
		{
			if (x[j] < x[low]) low = j;
		}
		if (i != low) swap(x[i],x[low]);
	}
	for (i=0;i<length;i++)
		cout << x[i] << " ";
	cout << endl; }

////////////////////////////////////////////
// we can also order strings of characters:
////////////////////////////////////////////

void swap(string & str1, string & str2)
{
	string tmp_string = str1;
	str1 = str2;
	str2 = tmp_string;
}

void main_sort_three_strings()
{
	string x,y,z;
	cout << "type three words, then ENTER: ";
	cin >> x >> y >> z;
	cout << "you entered: " << x << "," << y << "," << z << endl;
	if (x > y) swap(x,y);
	if (y > z) swap(y,z);
	if (x > y) swap(x,y);
	cout << "here is the new order: " << x << "," << y << "," << z << endl;
}



