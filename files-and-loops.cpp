#include "library.h"

///////////////////////////////////////////////////////
// read integers from "data.txt" and output their 
// average on console
///////////////////////////////////////////////////////

void main()
{
	int number;
	double total=0;
	double average;
	ifstream fin("data.txt");
	if(fin.fail())
	{
		cout << "can't open input file" << endl;
	}
	else
	{
		cout << "file opened properly" << endl;
		int i = 0;
		while (true)
		{
			fin >> number;
			if (fin.eof()) break;
			i++;
			cout << "i = " << i << "; number = " << number;
			total = total + number;
			cout << " total = " << total << endl;
		}
		average=total/i;
		cout << "the average of " << i <<" numbers is " << average << endl;
		fin.close();
	}
}

////////////////////////////////////////////////
// calculate x square for a series of values,
// then write the results to "data_square.txt"
////////////////////////////////////////////////

void main_write()
{
	ofstream fout("data_square.txt");
	if(!fout)
	{
		cout<<"can't open output file!"<<endl;
	}
	else
	{
                int x = 1;
		while(x<=10)
		{
			fout << x*x << endl;
			x++;
		}
		cout << "work finished" << endl;
		fout.close();
	}
}

////////////////////////////////////////////////
// combining read and write in a single program
////////////////////////////////////////////////

void main_read_and_write()
{
	int age, last_weight, this_weight;
	ifstream fin("weight.txt");
	if(!fin)
		cout << "can't open input file!" << endl;
	else
	{
		ofstream fout("weight_gain.txt");
		if(!fout)
			cout << "can't open output file!" << endl;
		else
		{
			while(!fin.eof())
			{
				fin  >> age >> last_weight >> this_weight;
				cout << "age: " << age << " " << last_weight << " " << this_weight << endl;
				fout << "age: " << age << "; weight gain: " << this_weight-last_weight << endl;
			}
			cout << "finished" << endl;
			fout.close();
			fin.close();
		}
	}
}

///////////////////////////////////////////////
// find the smallest element in a array 
///////////////////////////////////////////////


int find_smallest_element(int const x[], int const size)
{
	int smallest = x[0];
	int i = 1;
	while (i<size)
	{
		if (x[i] < smallest) smallest = x[i];
		i++;
	}
	return(smallest);
}


void main()
{
	int const length = 5;
	int x[length] = {2,4,6,3,-5};
	int smallest = find_smallest_element(x,length);
	cout << "the value of the smallest element is " << smallest << endl;
}



///////////////////////////////////////////////
// three ways to use a loop in the
// search-for-smallest-in-array algorithm 
///////////////////////////////////////////////


int find_smallest_B(int x[], int size)
{
	int index_of_smallest = 0;
	int i = 1;
	while(i<size)
	{
		if (x[i] < x[index_of_smallest])
			index_of_smallest = i;
		i++;
	}
	return(index_of_smallest);
}

int find_smallest_C(int x[], int size)
{
	int index_of_smallest = 0;
	int i = 1;
	do
	{
		if (x[i] < x[index_of_smallest])
			index_of_smallest = i;
		i++;
	}
	while (i<size);
	return(index_of_smallest);
}


int find_smallest_A(int x[], int size)
{
	int index_of_smallest = 0;
	for (int i=1;i<size;i++)
		if (x[i] < x[index_of_smallest]) index_of_smallest = i;
	return(index_of_smallest);
}

void output_array_on_console(int x[], int size)
{
	int i;
	for (i=0;i<size;i++)
		cout << x[i] << " ";
	cout << endl;
}

void main()
{
	int const length = 5;
	int x[length] = {2,4,6,3,-5};
	int lowest = find_smallest_B(x,length);
	cout << "here is what the array contains: " << endl;
	output_array_on_console(x,length);
	cout << "the smallest element is " << x[lowest] << endl;
}

