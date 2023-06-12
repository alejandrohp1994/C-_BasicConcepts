#include "library.h"

///////////////////////////////////////
//  REVERSING THE ORDER OF THE ELEMENTS
//  IN AN ARRAY
///////////////////////////////////////

void swap_them(int x[], int i, int j)
{
	int tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void print_array(int const x[], int const size)
{
	for (int i=0; i<size; i++)
		cout << x[i] << " ";
	cout << endl;
}

void main()
{
	int const size = 7;
	int x[size] = {1,2,3,4,5,6,7};
	print_array(x,size);
	for (int i=0;i<size/2;i++)
		swap_them(x,i,size-1-i);
	print_array(x,size);
}


///////////////////////////////////////
//   BUBBLE SORT
///////////////////////////////////////

void swap_them(int x[], int i, int j)
{
	int tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void print_array(int const x[], int const size)
{
	for (int i=0; i<size; i++)
		cout << x[i] << " ";
	cout << endl;
}

void bubble_s(int x[], int const size, bool ascending)
{
	bool action;
	do
	{
		action = false;
		for (int i=0;i<size-1;i++)
		{
			if ((ascending && (x[i]>x[i+1])) || (!ascending && (x[i]<x[i+1])))
			{
				swap_them(x,i,i+1);
				action = true;
			}

		}
	}
	while (action);
}

void main()
{
	int const size = 6;
	int x[size] = {2,5,-2,1,0,8};
	print_array(x,size);
	bubble_s(x,size,false);
	print_array(x,size);
}


///////////////////////////////////////
//   MERGE
///////////////////////////////////////

void print_array(int const x[], int const size)
{
	for (int i=0; i<size; i++)
		cout << x[i] << " ";
	cout << endl;
}

void merge(int z[], int x[], int y[], int const size)
{
	int ix = 0, iy = 0, iz = 0;
	for (iz=0;iz<2*size;iz++)
	{
		if (x[ix]<y[iy]) {z[iz] = x[ix]; ix++;}
		else {z[iz] = y[iy];iy++;}
		if (ix>size || iy>size) break;
	}
	while (ix<size)
		{z[iz] = x[ix]; ix++; iz++;}
	while (iy<size)
		{z[iz] = y[iy]; iy++; iz++;}
}	

void main()
{
	int const size = 5;
	int x[size] = {1,3,8,9,10};
	int y[size] = {5,6,7,11,19};
	int z[2*size];
	merge(z,x,y,size);
	cout << "first array: " << endl;
	print_array(x,size);
	cout << "second array: " << endl;
	print_array(y,size);
	cout << "merged arrray: " << endl;
	print_array(z,2*size);
}


////////////////////////////////////////////
//   INSERT A NUMBER INTO A PRE-SORTED ARRAY
////////////////////////////////////////////

int insert(int x[], int size, int number)
{
	int loc=size;
	for (int i=0;i<size;i++)
		if (x[i]>number) {loc=i;break;}
	for (int i=size;i>loc;i--) x[i]=x[i-1];
	x[loc]=number;
	return(size+1);
}

void print_arr(int x[], int size)
{
	for (int i=0;i<size;i++)
		cout << x[i] << " ";
	cout << endl;
}

void main()
{
	int size = 7;
	int x[100] = {1,3,9,19,23,32,50};
	print_arr(x,size);
	size = insert(x,size,4);
	print_arr(x,size);
}

