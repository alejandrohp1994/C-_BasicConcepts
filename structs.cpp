#include "library.h"

////////////////////////////////////////////////////////
// a simple example of a struct
// defining a type, and then the variable of this type,
// reading concrete values from the console
///////////////////////////////////////////////////////

struct mytype
{
	string name;
	int age;
};

void print_st(mytype st)
{
	cout << "the student's name is " << st.name;
	cout << " and his age is " << st.age;
}

void main_mytype()
{
	mytype st;
	st.name = "john";
	st.age = 20;
	print_st(st);
}

///////////////////////////////////////////////////
// a more sophisticated version of the program:
// the values read are stored in a file
///////////////////////////////////////////////////

struct mytype
{
	string name;
	int age;
};

void print_students_on_monitor(mytype st[],int const size)
{
	cout << endl << "HERE ARE THE STUDENTS YOU HAVE ENTERED: " << endl;
	for (int i=0;i<size;i++)
	{
		cout << i << ": ";
		cout << "name: " << st[i].name << "; age: " << st[i].age << endl;
	}
}

void read_students_from_keyboard(mytype st[],int const size)
{
	for (int i=0;i<size;i++)
	{
		cout << "enter name: ";
		cin >> st[i].name;
		cout << "enter age: ";
		cin >> st[i].age;
	}
}

bool store_in_file(char str[],mytype st[],int const size)
{
	ofstream fout(str);
	if (!fout)
	{
		cout << "cannot open output file" << endl;
		return(false);
	}
	for (int i=0;i<size;i++)
		fout << st[i].name << " " << st[i].age << endl;
	fout.close();
	return(true);
}

void main()
{
	char str[80];
	cout << "give me the file name: ";
	cin >> str; // enter a name such as "data.txt"
	int const size = 3;
	mytype st[size];
	read_students_from_keyboard(st,size);
	bool succeed = store_in_file(str,st,size);	
	print_students_on_monitor(st,size);
	if (!succeed) 
		cout << "I did not manage to write them to the file" << endl;
}

//////////////////////////////////////////////////////////////
// a example of passing the file handle ("fin") to a function:
//          reading a list of words
// once read, the result i sprinted on the monitor
//////////////////////////////////////////////////////////////

int read_word_list(ifstream & fin, string arr[], int size)
{
	for (int i=0;i<size;i++)
	{
		fin >> arr[i];
		if (fin.fail()) return(i);
	}
}

void print_words_on_monitor(string arr[], int size)
{
	for (int i=0;i<size;i++)
		cout << arr[i] << endl;
}

void main()
{
	int const size = 90;
	string words[size];
	ifstream fin("file_words.txt");
	int const how_many = read_word_list(fin,words,size);
	fin.close();
	for (int i=0;i<how_many;i++)
		if (words[i][0]>='a' && words[i][0]<='z') 
			words[i][0] -= ('a' - 'A');
	print_words_on_monitor(words,how_many);
}

/////////////////////////////////////////////////////
// A modifiction for practicing:
// Copy the array into another, but ignore all
// articles. Then sort this new array alphabetically
/////////////////////////////////////////////////////


////////////////////////////////////////////
// NESTED STRUCTS
// converting one struct array to another
////////////////////////////////////////////

struct date_type
{
	int year;
	int month;
	int day;
};

struct st_type_O
{
	string name;
	int DOB;
};

struct st_type_N
{
	string name;
	date_type d;
};

void fill_with_values(st_type_O st_old[], int const size)
{
	for (int i=0;i<size;i++)
	{
		cout << "name: ";
		cin >> st_old[i].name;
		cout << "DOB: ";
		cin >> st_old[i].DOB;
	}
}

void convert_to_new(st_type_O st_old[], st_type_N st_new[], int const size)
{
	for (int i=0;i<size;i++)
	{
		st_new[i].name    =  st_old[i].name;
		st_new[i].d.year  =  st_old[i].DOB / 10000;
		st_new[i].d.month =  (st_old[i].DOB % 10000) / 100;
		st_new[i].d.day   =  st_old[i].DOB % 100;
	}
}

void print_old(st_type_O st_old[], int const size)
{
	cout << endl << "THE OLD VERSION:" << endl;
	for (int i=0;i<size;i++)
	{
		cout << st_old[i].name << " " << st_old[i].DOB << endl;
	}
}

void print_new(st_type_N st_new[], int const size)
{
	cout << endl << "THE NEW VERSION: " << endl;
	for (int i=0;i<size;i++)
	{
		cout << st_new[i].name << " " << 
			st_new[i].d.year << " " << st_new[i].d.month << " " << st_new[i].d.day << endl;
	}
}

void main()
{
	int const size = 2;
	st_type_O   st_old[size];
	st_type_N   st_new[size];
	fill_with_values(st_old,size);
	convert_to_new(st_old,st_new,size);
	print_old(st_old,size);
	print_new(st_new,size);
}

