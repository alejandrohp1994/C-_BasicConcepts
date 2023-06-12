#include "library.h"

///////////////////////////////////////////////////////////////////
// A trivial program, consisting only of a "main()" function
///////////////////////////////////////////////////////////////////

void main()
{
	cout << "Hi students, this is C++!";
}

//////////////////////////////////////////////////////////////////////////////////
// Very simple exercises with functions returning int and double constants.
// Only one "void main()" with the caller is given here, others are analogous.
// If you want to run these functions on your computer, do not forget to
// replace "void main_c_to_f()" with "void main()" and likewise with
// the other functions.
// important: the need for a "return"; the need for the type of the returned value
//////////////////////////////////////////////////////////////////////////////////


int square_area(int const side)
{
	int const area = side * side;
	return(area);
}

int rectangle_area(int const width, int const height)
{
	int const area = width * height;
	return(area);
}

int c_to_f(int const c_temperature)
{ 
	int const FT = 32 + (c_temperature*1.8);
	cout << "you are working with INTEGER values" << endl;
	return(FT);
}

double c_to_f(double const c_temperature)
{
	double const FT = 32 + (c_temperature*1.8);
	cout << "you are working with DOUBLE values" << endl;
	return(FT);
}


void main_c_to_f()
{
	double const tc = 21.0;
	double const tf = c_to_f(tc);
	cout << "The fahrenheit temperature is: " << tf << endl;
}

//////////////////////////////////////////////////////
// As additional practice, try the following variations:
// 1-argument function: area of a circle
// 2-argument function: area of a triangle
// 3-argument function: volume of a prism
//////////////////////////////////////////////////////



///////////////////////////////////////////////////
// simple experiments with DOUBLE and INT division
// as before, replace the name with "void main()"
///////////////////////////////////////////////////

void main_int_vs_double()
{
	cout << 15/2 << endl;
	cout << 15/2.0 << endl;
	cout << 15.0/2 << endl;
	int const x = 15;
	cout << x/2.0 << endl;
	double const y = 15;
	cout << y/2 << endl;
}


/////////////////////////////////////////////////////////////
// an example illustrating "integer division" and "modulo" (%)
////////////////////////////////////////////////////////////

void main_modulo()
{
	int x = get_calendar_date();
	int const year = x / 10000;
	int const day = x % 100;
	int const month = (x % 10000) / 100;
//	int const month = (x / 100) % 100;
	cout << " original integer: " << x << endl;
	cout << "year  = " << year << endl;
	cout << "month = " << month << endl;
	cout << "day   = " << day << endl;
}


////////////////////////////////////////////////////////
// another little exercise:
// a function returning the average of two numbers
// important: be careful about the type (int or double?)
////////////////////////////////////////////////////////

double average(double const x, double const y)
{
	double const z = (x+y)/2;
	return(z);
}

void main_average()
{
	double const first_number = 4;
	double const second_number = 7;
	double const result = average(first_number,second_number);
	cout << "x = " << first_number;
	cout << ";  y = " << second_number;
	cout << ";  z = " << result << endl;
}


///////////////////////////////////////////////////////////////////////////
// Let us now turn our attention to graphics, using functions from library.h
// Here are some (very clumsily written) functions to draw simple geometric
// figures. Later, we will learn better programming techniques. 
////////////////////////////////////////////////////////////////////////////

void draw_triangle(int const x, int const y, int const side)
{  set_heading_degrees(90);
   move_to(x,y);
   draw_distance(side);
   turn_right_by_degrees(120);
   draw_distance(side);
   turn_right_by_degrees(120);
   draw_distance(side); }

void draw_square(int const x, int const y, int const side, int const color)
{  set_pen_color(color);
   set_heading_degrees(90);
   move_to(x,y);
   start_shape();
   draw_distance(side);        note_position();
   turn_right_by_degrees(90);
   draw_distance(side);        note_position();
   turn_right_by_degrees(90);
   draw_distance(side);        note_position();
   turn_right_by_degrees(90);
   draw_distance(side);        note_position();
   fill_shape(); }

void draw_pentagon(int const x, int const y, int const side, int const color)
{  set_pen_color(color);
   set_heading_degrees(90);
   move_to(x,y);
   start_shape(); 
   draw_distance(side); note_position();
   turn_right_by_degrees(72);  
   draw_distance(side); note_position();
   turn_right_by_degrees(72);  
   draw_distance(side); note_position();
   turn_right_by_degrees(72);  
   draw_distance(side); note_position();
   turn_right_by_degrees(72); 
   draw_distance(side);  note_position();
   fill_shape();}

void main_geometric_figures()
{
	int const x = 50;
 	int const y = 100;
	int const side = 40;
	make_window(500,500);
	set_pen_width(3);
	set_pen_color(color::blue);
	draw_triangle(x,y,side);
//	draw_square(x,y,side,color::green);
//	draw_pentagon(x,y,side,color::black);
}

