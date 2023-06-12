#include "library.h"

///////////////////////////////////////////////////
// test the quality of the random-number generator
///////////////////////////////////////////////////

void main()
{
	int num;
	int const N = 100;
	int x[10];
	for (int i=0;i<10;i++) x[i]=0;
	for (int i=0;i<N;i++)
	{
		num = random_in_range(0,9);
		x[num]++;
	}
	for (int i=0;i<10;i++)
		cout << "i=" << i << ":  x[i] " = << x[i] << endl;
}

//////////////////////////////////////////
// Here are two examples of how PI can be
// calculated using "inifite" sequences
//////////////////////////////////////////

double calculate_pi_madhava(int const n)
{
	int i=0;
	double result = 0;
	double r;
	while (i<=n)
	{
		r = 1.0/(2*i+1);
		if (i%2==0)	result = result + r;
		else result = result - r;
		i = i + 1;
	}
	return(result*4);
}

double calculate_pi_euler(int const n)
{
	int i = 1;
	double result = 0;
	while (i<=n)
	{
		result = result + 1.0/(i*i);
		i=i+1;
	}
	result = sqrt(6*result);
	return(result);
}

void main()
{
	int const N = 300;
	cout << "Leibnitz result is: " << calculate_pi_madhava(N) << endl;
	cout << "Euler result is:    " << calculate_pi_euler(N) << endl;
}

//////////////////////////////////////////////////////
// a modification for further practice: in the digits
// of pi, find the first sequence of two 6s ("..66..")
//////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
// another exercise write a program that converts a roman
// number into a decadic form (use the ancient romans, not 
// the medieval, so that 90 is LXXXX, and not XC)
//  e.g. MCCCLCVIIII = 1369
//////////////////////////////////////////

////////////////////////////////////////////////
// Some time ago, we tried the following function as
// an exercise in integer division and modulus
////////////////////////////////////////////////

void print_time_and_day(int const D, int const T)
{ int const day = D % 100;
  int const month = (D / 100) % 100;
  int const year = D / 10000;
  int const hour = T / 10000 + 2;
  int const minute = (T / 100) % 100;
      print("  year: "); print(year);   new_line();
      print(" month: "); print(month);  new_line();
	  print("   day: "); print(day);    new_line();
	  print("  hour: "); 
	  if (hour > 12) {print(hour-12); print(" p.m.");}
	  else print(hour);
	  new_line();
	  print("minute: "); print(minute); new_line(); }

void main()
{ int const T = get_clock_time();
  int const D = get_calendar_date();
  print_time_and_day(D,T);
  cout << endl;
}

