//#include "library.h"
//
//////////////////////////////////////////////////
//// introduce "cin" and "cout" for intput/output
//// (note how flexible they are)
//////////////////////////////////////////////////
//
//void main_1()
//{ 
//	int x;
//	cout << "Enter your age: ";
//	cin >> x;
//	if (x > 12 && x < 20) 
//		cout << "Yes, " << x << " is a teenager age" << endl;
//	else cout << "No, " << x << " is not a teenager age" << endl;
//}
//
//
/////////////////////////////////////////////////
//// a new variable type: "char"
//// print N repetitions of a character
/////////////////////////////////////////////////
//
//void print_N_char(int const N, char const c)
//{
//	int i=1;
//	while (i <= N)
//	{
//		cout << c;
//		i = i + 1;
//	}
//}
//
//void main_3()
//{
//	char const c = 'a';
//	int const N = 4;
//	print_N_char(N,c);
//}
//
//////////////////////////////////////////////////////////
//// converting characters into their ASCII integer codes
//////////////////////////////////////////////////////////
//
//void main()
//{
//	char c;
//	while (true)
//	{
//		cout << "enter a character ";
//		cin >> c;
//		cout << " the code is: " << (int)c << endl;
//		if ((int)c == -89) break;
//	}
//}
//
///////////////////////////////
//// uncapitalize
///////////////////////////////
//
//void main_uncapitalize()
//{
//	char c;
//	int code_of_c;
//	while (true)
//	{
//		cout << "enter a character: ";
//		cin >> c;
//		if (c>='A' && c<='Z') c = c + ('a' - 'A');
//		cout << "final value: " << c << endl;
//	}
//}
//
/////////////////////////////////////////////////////
//// an example where recursion is better than loops:
//// spell out an integer
////////////////////////////////////////////////////
//
//void say(int const n)
//{
//	if (n==0)  print("ZERO");
//	else if (n==1) print("ONE");
//	else if (n==2) print("TWO");
//	else if (n==3) print("THREE");
//	else if (n==4) print("FOUR");
//	else if (n==5) print("FIVE");
//	else if (n==6) print("SIX");
//	else if (n==7) print("SEVEN");
//	else if (n==8) print("EIGHT");
//	else if (n==9) print("NINE");
//	else if (n==10) print("TEN");
//	else if (n==11) print("ELEVEN");
//	else if (n==12) print("TWELVE");
//	else if (n==13) print("THIRTEEN");
//	else if (n==14) print("FOURTEEN");
//	else if (n==15) print("FIFTEEN");
//	else if (n==16) print("SIXTEEN");
//	else if (n==17) print("SEVENTEEN");
//	else if (n==18) print("EIGHTEEN");
//	else if (n==19) print("NINETEEN");
//	else if (n==20) print("TWENTY");
//	else if (n==30) print("THIRTY");
//	else if (n==40) print("FORTY");
//	else if (n==50) print("FIFTY");
//	else if (n==60) print("SIXTY");
//	else if (n==70) print("SEVENTY");
//	else if (n==80) print("EIGHTY");
//	else if (n==90) print("NINETY");
//	else if (n <= 99)
//	{
//		say((n/10)*10);
//		print(" ");
//		say(n%10);
//	}
//	else if (n <= 999)
//	{
//		say(n/100);
//		print(" HUNDRED");
//		if (n%100 != 0)
//		{
//			print(" AND ");
//			say(n%100);
//		}
//	}
//	else if (n <= 999999)
//	{
//		say(n/1000);
//		int const rest = (n%1000);
//		print(" THOUSAND");
//		if (rest != 0)
//		{
//			if (rest < 100) print(" AND");
//			print(" ");
//			say(n % 1000);
//		}
//	}
//	else print("this number is too big for me");
//}
//
//void main()
//{
//	say(24101);
//	new_line();
//}
//
