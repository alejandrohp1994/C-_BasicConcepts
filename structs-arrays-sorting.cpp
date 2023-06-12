#include "library.h"

///////////////////////////////////////////
// another example of a STRUCT
///////////////////////////////////////////

struct studenttype
{
	string name;
	int age;
	string grades[2];
};

void swap(studenttype & x, studenttype & y)
{
	studenttype tmp = x;
	x = y;
	y = tmp;
}

void print_students(studenttype x[], int const size)
{
	for (int i=0,i<size,i++)
	{
		cout << "name: " << x[i].name;
		cout << ", age: " << x[i].age;
		cout << endl;
	}
}

void main_structs()
{
	int i;
	int const size = 2;
	studenttype st[size];
	i = 0;
	while (i<size)
	{
		cout << "Give me a name: ";
		cin >> st[i].name;
		cout << "Give me age: ";
		cin >> st[i].age;
		cout << "Give me the grade in C++: ";
		cin >> st[i].grades[0];
		cout << "Give me the grade in math: ";
		cin >> st[i].grades[1];
		cout << endl;
		i++;
	}
	cout << "THE INPUT INFORMATION:" << endl;
	i = 0;
	print_students(st,2);
	swap(st[0],st[1]);
	cout << "AFTER THE SWAP:" << endl;
	i = 0;
	while (i<size)
	{
		cout << st[i].name << " " << st[i].age << " " << st[i].grades[0] <<
			" " << st[i].grades[1] << endl;
		i++;
	}
	cout << "I am done\n";
}

///////////////////////////////////
// Strings are a bit like arrays
///////////////////////////////////

void main()
{
	string s = "book";
	for (int i=0;i<4;i++)
		cout << s[i] << " " ;
	cout << endl;
	s[0]++;
	cout << s << endl;
	s[3] = 'l';
	cout << s << endl;
	cout << "the length of this string is: " << s.length() << endl;
}

/////////////////////////////////
// two-dimensional arrays
/////////////////////////////////

void print_array(int a[][3])
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if (a[i][j] < 10) cout << " " << a[i][j] << "  ";
			else cout << a[i][j] << "  ";
		}
		cout << endl;  
	}
}

void sum_of_arrays(int a[][3], int x[][3], int y[][3])
{
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			a[i][j] = x[i][j] + y[i][j];
}

void main()
{
	int z[3][3];
	int x[3][3] = {{1,2,3},
	              {4,5,6},
	              {7,8,9}};
	int y[3][3] = {{3,2,4},
	              {6,1,2},
	              {0,1,1}};
	sum_of_arrays(z,x,y);
	cout << "Here is the first array: " << endl;
	print_array(x);
	cout << "Here is the second array: " << endl;
	print_array(y);
	cout << "Here is the sum of the two arrays: " << endl;
	print_array(z);
}

////////////////////////////////////////////////
// variations for independent practicing:
// - find the smallest element in a 2-dim array
// - a function that calculates the outer product
//   of two vectors
////////////////////////////////////////////////




/////////////////////////////////////
// the simplest sorting algorithm
/////////////////////////////////////

void swap(int & x, int & y)
{
	int tmp = y;
	y = x;
	x = tmp;
}

void main()
{
	int const length = 5;
	int x[length] = {-32,3,2,-8,-119};
	for (int i=0;i<length;i++)
	{
		int smallest = i;
		for (int j=i+1;j<length;j++)
			if (x[j]<x[smallest]) smallest = j;
		if (i!=smallest) swap(x[i],x[smallest]);
	}
	for (int i=0;i<length;i++)
		cout << x[i] << " ";
	cout << endl;
}

