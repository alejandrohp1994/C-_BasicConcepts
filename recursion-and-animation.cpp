#include "library.h"

////////////////////////////////////////////////////
// a small exercise for recursive functions: print 
// an ascending or descending sequence of integers
////////////////////////////////////////////////////

void print_seq(int const N)
{
	if (N>0)
	{
		cout << N << " ";
		print_seq(N-1);
	}
}

void print_seq(int const i, int const MAX)
{
	if (i<=MAX)
	{
		cout << i << " ";
		print_seq(i+1,MAX);
	}
}

void main()
{
	print_seq(1,9);
	cout << endl;
}

///////////////////////////////////////////////////////////
// another little exercise (analyzing recursive functions):
// what will the following function print?
///////////////////////////////////////////////////////////

void f1(int const n)
{
	if (n > 9)
	f1(n / 10);
	cout << " " << n % 10;
}

void main()
{
	f1(17426);
}


////////////////////////////////////////////////////////////
// use a recursive function to find the number of digits in
// an integer (e.g., 4321 has 4 digits)
////////////////////////////////////////////////////////////

int how_many_digits(int const N)
{
	if (N<10) return(1);
	else return(1 + how_many_digits(N/10));
}

void main()
{
	int const x = 321;
	int const result = how_many_digits(x);
	cout << x << " has " << result << " digits" << endl;
}

////////////////////////////////////////////////////////////
// use a recursive function to print the fibonacci sequence
////////////////////////////////////////////////////////////


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


///////////////////////////////////////////////
// an illustration olf a recursive function:
// drawing a circle as a polygon of many sides
///////////////////////////////////////////////

void line_and_turn(int const N, double const side, int const angle)
{
	if (N > 0)
	{
		draw_distance(side);
		turn_right_by_degrees(angle);
		line_and_turn(N-1,side,angle);
	}
}

void draw_circle(double const x, double const y, double const radius)
{
	double const circumference = 2 * radius * 3.14;
	double const side = circumference / 360;
	move_to(x,y-radius);
	line_and_turn(360,side,1);
}

void main()
{
	int const x = 100;
	int const y = 100;
	double const radius = 50;
	make_window(500,300);
	set_pen_width(3);
	set_pen_color(color::brown);
	set_heading_degrees(90);
	draw_circle(x,y,radius);
}

///////////////////////////////////////////////
//  first attempt at animation:
//  draw, recursively, a straight line of dots
///////////////////////////////////////////////

void draw_a_series_of_dots(int const x, int const y,
		int const N, int const dist)
{
	if (N > 0)
	{
		move_to(x,y);
		draw_point();
		wait(0.02);
		draw_a_series_of_dots(x+dist,y,N-1,dist);
	}
}

void main_straight_line()
{
	int const x = 20;
	int const y = 100;
	int const N = 100;
	int const dist = 5;
	make_window(700,300);
	set_pen_width(3);
	set_pen_color(color::black);
	draw_a_series_of_dots(x,y,N,dist);
}

///////////////////////////////////////////////
//  slightly modified version of the previous:
//  the line turns down upon hitting an obstacle
///////////////////////////////////////////////

void draw_a_series_of_dots(int const x, int const y,
	   int const N, int const dist, int const x_obst)
{
	if (N > 0)
	{
		move_to(x,y);
		draw_point();
		wait(0.01);
		if (x<x_obst-3) draw_a_series_of_dots(x+dist,y,N-1,dist,x_obst);
		else draw_a_series_of_dots(x,y+dist,N-1,dist,x_obst);
	}
}

void main_line_with_an_obstracle()
{
	int const x = 50;
	int const y = 100;
	int const N = 400;
	int const dist = 1;
	int const x_obst = 300;
	make_window(700,300);
	set_pen_width(3);
	set_pen_color(color::black);
	fill_rectangle(x_obst,50,20,200);
	set_pen_color(color::red);
	draw_a_series_of_dots(x,y,N,dist,x_obst);
}


///////////////////////////////////////////////
// a more impressive example of animation:
// plotting the sine function
///////////////////////////////////////////////

void system_of_coord()
{
	make_window(500,500);
	set_pen_color(color::black);
	set_pen_width(2);
	set_heading_degrees(90);
	move_to(50,250);   
	draw_distance(400);
	set_heading_degrees(180);
	move_to(250,50);
	draw_distance(400);
}

void plot_the_sine_graph(double const x)
{
	if (x < 6.28)
	{
		double const y = sin(x);
		draw_point(20*x+250,-100*y+250);
		wait(0.01);
		plot_the_sine_graph(x+0.04);
	}
}

void main()
{
	double const x = -6.28;
	system_of_coord();
	set_pen_color(3);
	set_pen_color(color::blue);
	plot_the_sine_graph(x);
}


/////////////////////////////////////////////////////////////
// and yet another example of a recursive call in animation
// (a nice picture)
////////////////////////////////////////////////////////////

void draw_them(int const x, int const y, int const N, int const degr, int const length)
{
	if (N>0)
	{
		move_to(x,y);
		set_heading_degrees(degr);
		draw_distance(length);
		wait(0.01);
		draw_them(x,y,N-1,degr+5,length);
	}
}

void main_draw_a_nice_picture()
{
	int const x = 100;
	int const y = 100;
	int const degr = 0;
	int const length = 80;
	int const N = 72;
	make_window(500,500);
	set_pen_width(1);
	draw_them(x,y,N,degr,length);
}

////////////////////////////////////////////
// BOOLEAN constants and Boolean functions
// AND .. &&
// OR ... ||
// NOT .. !
////////////////////////////////////////////

void main()
{
	bool const b1 = (5 > 3);
	bool const b2 = (5 == 6);
	print(b1 && !b1);
	new_line();
	print(b1 || b2);
	new_line();
}
