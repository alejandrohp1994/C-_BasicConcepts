#include "library.h"


/////////////////////////////////////////////////////////////
// a function that compares two numbers (returns a string)
// recursive call of this function
// in the main: a seed is set for a RANDOM NUMBER GENERATOR
////////////////////////////////////////////////////////////

string which_is_greater(int const n, int const m)
{
	if (n > m) return("the first is greater");
	if (n == m) return("they are equal");
	if (n < m) return("the second is greater");
}

void run_k_times(int const k)
{
	if (k > 0)
	{
	int const n = random_in_range(0,9);
	int const m = random_in_range(0,9);
	string const s = which_is_greater(n,m);
	cout << "n = " << n << ";  m = " << cout << m << endl;
	cout << s << endl;
	run_k_times(k-1);
	}
}

void main_random_numbers()
{
	srand(3);
	int const k = 5;
	run_k_times(k);
}

/////////////////////////////////////////
// Find the greatest common factor (GCF)
/////////////////////////////////////////

int GCF(int const x, int const y)
{
	if (x % y == 0) return(y);
	else return(GCF(y,x%y));
}

void main_GCF()
{	
	int const x = 300;
	int const y = 500;
	cout << "GCF of " << x << " and " << y << " is " << GCF(x,y) << endl;
}

/////////////////////////////////////////
// find square root by interval halving
/////////////////////////////////////////

double sq_r(double const lower, double const upper,
			double const number, double const min_error)
{
	double const r = (lower+upper) / 2;
	if (upper - lower < min_error) return(r);
	if (r*r > number) return(sq_r(lower,r,number,min_error));
	else return(sq_r(r,upper,number,min_error));
}

void main_square_root()
{
	double const number = 100;
	double const result = sq_r(0,number,number,0.001);
	cout << "square root of " << number << " is " << result << endl;
}


//////////////////////////////////////////////////
// "Print integers beautifully"
//////////////////////////////////////////////////

void print_with_leading_zeros(int const x)
{
	if (x == 0) print("000");
	else if (x < 10)  cout << "00" << x;
	else if (x < 100) cout <<  "0" << x;
	else cout << x;
}

void print_beautifully(int const x)
{
	if (x < 1000) cout << x;
	else 
	{
		print_beautifully(x/1000);
		cout << ","
        	print_with_leading_zeros(x%1000);
	}
}

void main_print()
{   
	int const x = 1000000;
	print_beautifully(x);
	cout << endl;
}


/////////////////////////////////
// SPIRALS - a kick-off version
/////////////////////////////////

void draw_point_in_polar(int const x, int const y, int const radius, int const angle)
{
	set_heading_degrees(angle);
	move_to(x,y);
	move_distance(radius);
	draw_point();
}

void draw_spirals(int const N, int const x, int const y, 
		int const radius, int const angle)
{
	if (N>0)
	{
		draw_point_in_polar(x,y,radius,angle);
		wait(0.01);
		draw_spirals(N-1,x,y,radius+1,angle+5);
	}
}

void main()
{
	int const x = 300;
	int const y = 300;
	int const N = 100;
	int const radius = 10;
	int const angle = 10;
	make_window(600,600);
	set_pen_width(3);
	set_font_size(36);
	draw_spirals(N,x,y,radius,angle);
}

//////////////////////////////////////////////
// a better version of the SPIRALS program
//////////////////////////////////////////////

void set_up_window()
{
	make_window(600,600);
	set_pen_width(3);
	set_font_size(36);
}

void message(int const N, string const s)
{
	if (N>0)
	{
		set_pen_color(color::green);
		wait(0.2);
		fill_rectangle(0,0,600,60);
		set_pen_color(color::black);
		wait(0.2);
		move_to(180,35);
		write_string(s);
		message(N-1,s);
	}
}

void draw_point_in_polar(int const x, int const y, int const radius,
						 int const angle, int const color)
{
	set_pen_color(color);
	set_heading_degrees(angle);
	move_to(x,y);
	move_distance(radius);
	draw_point();
}

void draw_spirals(int const N, int const x, int const y,
				  int const radius, int const angle)
{
	int const max_radius = 400;
	if (N>0 && radius < max_radius)
	{
		draw_point_in_polar(x,y,radius,angle,color::red);
		draw_point_in_polar(x,y,radius,-angle,color::green);
		wait(0.01);
		draw_spirals(N-1,x,y,radius+1,angle+5);
	}
	else if (N <= 0)
	{
		message(5,"points exhausted");
	}
	else if (radius >= max_radius)
	{
		message(5,"max radius exceeded");
	}
}

void main_SPIRALS()
{
	int const x = 300;
	int const y = 300;
	int const N = 300;
	int const radius = 10;
	int const angle = 10;
	set_up_window();
	draw_spirals(N,x,y,radius,angle);
}

///////////////////////////////
// BROWNIAN MOTION
///////////////////////////////

void brownian(int const N, int const length)
{
	if (N>0)
	{
		int const angle = random_in_range(1,360);
		set_heading_degrees(angle);
		draw_distance(length);
		wait(0.01);
		brownian(N-1,length);
	}
}

void main_BROWNIAN()
{
	int const N = 1000;
	int const length = 5;
	make_window(500,500);
	set_pen_width(2);
	set_pen_color(color::blue);
	move_to(250,250);
	brownian(N,length);
}


////////////////////////////////////////
// BROWNIAN MOTION WITH AN ENDLESS LOOP
////////////////////////////////////////

void brownian(int const length)
{
	while (true)
	{
		int const angle = random_in_range(1,360);
		set_heading_degrees(angle);
		draw_distance(length);
		wait(0.01);
	}
}

void main_BROWNIAN()
{
	int const length = 5;
	make_window(500,500);
	set_pen_width(2);
	set_pen_color(color::blue);
	move_to(250,250);
	brownian(length);
}

