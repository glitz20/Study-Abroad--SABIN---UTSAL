//This program helps the user to find a best fit of study abroad colleges according to their choices

//							Sabin Sapkota						Utsal Shrestha

#include <iostream>
#include <string>
#include <thread>
#include "user.h"

using namespace std;

void welcome();

string countrychoice();//function for choosing the country
int yearchoice();//function for choosing the expected year of travel
string subjectchoice();//function for choosing the subject
char pricerange();//function for specifying the user's price range
void condition(string country, int year, string subject, char price);//filter condition function
void halt();
string capitalize(string n);//capitalizes a string

int main()
{
	string username;//intro
	int again = 0;
	welcome();//calls on the welcome screen function
	cout << "\tPlease enter your name: ";
	getline(cin, username);


	size_t found = username.find_first_of(" ");//to use only the user's first name
	string user= username.substr(0,found);

	tryagain:
	if (again == 0) {
		cout << "\n\tHi, " << user << "! Great to have you here!\n\n";
		cout << "\tPlease go through the filters. You can enter 0 if you have no preference.\n";
	}
	else
	{
		halt();
		again = 0;
		system("cls");
		welcome();
		cout << "\n\tHi, " << user << "! Great to have you here again!\n\n";
		cout << "\tPlease go through the filters. You can enter 0 if you have no preference.\n";
	}
	string country=countrychoice();
	country = capitalize(country);//passed to capitalize function which returns capitalized string

	int year = yearchoice();
	cin.ignore();

	string subject = subjectchoice();
	subject = capitalize(subject);//passed to capitalize function which returns capitalized string
		

	char price = pricerange();//converting into 'A' or 'B'
	if (price == 'a')
		price = 'A';
	if (price == 'b')
		price = 'B';
	for (int i=1;i<3;i++)
		halt();
	condition(country, year, subject, price);//this function takes in the country, year, subject and price. does not return anything
	halt();
	cout << "\tDo you want to try again? (1=Yes, any key to exit)";
	cin >> again;
	cin.ignore();
	if (again == 1)
		goto tryagain;
	return 0;
}


void welcome()//only prints the welcome screen. will be modified for final presentation.
{
	cout << "\n\n\t   **********************************************************************************************" << endl;
	cout << "\t   *                                                                                            *" << endl;
	cout << "\t   *                         Welcome to Pi-rate Study Abroad Program                            *" << endl;
	cout << "\t   *                                                                                            *" << endl;
	cout << "\t   *--------------------------------------------------------------------------------------------*" << endl;
	cout << "\t   *                                                                                            *" << endl;
	cout << "\t   * Pi-rate Study Program is a tool which helps you to choose the best study program according *" << endl;
	cout << "\t   *					to your need and fit.   		                *" << endl;
	cout << "\t   *                                                                                            *" << endl;
	cout << "\t   \\---o----o----o----o----o----o----o----o----o----o----o----o----o----o----o----o----o----o---/" << endl<< endl;
}

string capitalize(string n)
{
	for (int i = 0; n[i] != 0; i++)//takes in a string, converts into upperclass and returns it
		if (n[i] <= 122 && n[i] >= 97)
			n[i] -= 32;
	return n;
}

void halt()
{
	this_thread::sleep_for(1.5s);
}

string countrychoice()//asks user their country of choice and returns it
{
	string country;
	cout << endl << endl;
	cout << "\tCountries: We have many countries in different continents to choose from.\n";
	cout << "\tCHINA\n\tUNITED KINGDOM\n\tBRAZIL\n\tSPAIN\n\tHONGKONG\n\tNETHERLANDS\n\tAUSTRAILIA\n\n";

	cout << "\tPlease enter the one you like: ";
	getline (cin, country);
	cout << endl << endl;
	return country;

}

int yearchoice()//asks user their expected year of travel and returns it
{
	int year;
	cout << "\tWhich year do you to go (2016, 2017, 2018, 2019): ";
	cin >> year;
	return (year % 100);
}

 
string subjectchoice() // asks user their subject choice and returns i
{
	const int n = 4;
	string subject;
	string subjects[n] = { "Humanities", "Mathematics", "Computer Science", "Engineering" };
	cout << "\n\tWhich subject do you want to study?\n";
	for (int i = 0; i < 4; i++)
		cout << "\t" << subjects[i] << endl;
	cout << endl;
	cout << "\tPlease enter the subject you like: ";
	getline (cin, subject);
	cout << endl << endl;
	return subject;
}

char pricerange() //asks user their price range and returns a char value (either a or b)
{
	char price;
	cout << "\tWhich price range can you afford? ";
	cout << endl;
	cout << "\t a) $5000-$9000\n";
	cout << "\t b) $9000- $12000\n";

	cout << "\tDo note that scholarships are available.\n";
	cout << "\tPlease choose option a or b: ";
	cin >> price;
	cout << endl << endl;
	return price;
}

void condition(string country, int year, string subject, char price)//takes in the values. does not return anything
{
	abroadcount count;
	int counter = 0;

	//conditions for filtering. data in a class in separate header file (line 128 onwards)
	if ((country == "CHINA" || country == "0") && (subject == "HUMANITIES" || subject == "MATHEMATICS" || subject == "0") && (price == 'A' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.peking();
	}

	if ((country == "CHINA" || country == "0") && (subject == "COMPUTER SCIENCE" || subject == "ENGINEERING" || subject == "0") && (price == 'B' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.fudan();
	}

	if ((country == "UNITED KINGDOM" || country == "0") && (subject == "HUMANITIES" || subject == "MATHEMATICS" || subject == "0") && (price == 'B' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.oxford();
	}
	if ((country == "UNITED KINGDOM" || country == "0") && (subject == "COMPUTER SCIENCE" || subject == "ENGINEERING" || subject == "0") && (price == 'B' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.lse();
	}


	if ((country == "SPAIN" || country == "0") && (subject == "HUMANITIES" || subject == "MATHEMATICS" || subject == "0") && (price == 'A' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.granada();
	}
	if ((country == "SPAIN" || country == "0") && (subject == "COMPUTER SCIENCE" || subject == "ENGINEERING" || subject == "0") && (price == 'B' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.madrid();
	}

	if ((country == "HONGKONG" || country == "0") && (subject == "HUMANITIES" || subject == "MATHEMATICS" || subject == "0") && (price == 'A' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.hongkong();
	}
	if ((country == "HONGKONG" || country == "0") && (subject == "COMPUTER SCIENCE" || subject == "ENGINEERING" || subject == "0") && (price == 'B' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.hpi();
	}
	if ((country == "NETHERLANDS" || country == "0") && (subject == "HUMANITIES" || subject == "MATHEMATICS" || subject == "0") && (price == 'A' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.holland();
	}
	if ((country == "NETHERLANDS" || country == "0") && (subject == "COMPUTER SCIENCE" || subject == "ENGINEERING" || subject == "0") && (price == 'B' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.amsterdam();
	}
	if ((country == "AUSTRALIA" || country == "0") && (subject == "HUMANITIES" || subject == "MATHEMATICS" || subject == "0") && (price == 'A' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.canberra();
	}
	if ((country == "AUSTRALIA" || country == "0") && (subject == "COMPUTER SCIENCE" || subject == "ENGINEERING" || subject == "0") && (price == 'B' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.melbourne();
	}
	if ((country == "BRAZIL" || country == "0") && (subject == "HUMANITIES" || subject == "MATHEMATICS" || subject == "0") && (price == 'A' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.saopaulo();
	}
	if ((country == "BRAZIL" || country == "0") && (subject == "COMPUTER SCIENCE" || subject == "ENGINEERING" || subject == "0") && (price == 'B' || price == '0'))
	{
		counter += 1;
		cout << endl << counter << "." << endl;
		count.francu();
	}
	if (counter == 0)
		cout << "Sorry, no results found.\n\n";
	cout << endl;
}