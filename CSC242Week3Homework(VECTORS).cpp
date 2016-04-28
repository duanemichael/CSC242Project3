/*
Duane Michael
CSC 242 - Intro. to Programming Concepts & Methods
Week 3 - Homework (REWORKED WITH VECTORS!!!)
Professor - Dr. Alireza Farahani
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
The country class holds 3 values:
countryName, Population, and Area.
*/
class country
{
public:
	country();   //Default constructor
	country(string n, long p, double a);

				 //SET methods for country
	void setCountryName(string);
	void setPopulation(long);
	void setArea(double);

	//GET methods for country
	string getCountryName() const;
	long getPopulation() const;
	double getArea() const;

	double calcDensity() const; //Returns the population density
	void print() const;

private:
	string countryName;
	long population;
	double area;

};

country::country() //Default constructor; initiates values.
{
	population = 0;
	area = 0;
}

country::country(string n, long p, double a)
{
	countryName = n;
	population = p;
	area = a;
}

void country::setCountryName(string N)
{
	countryName = N;
}

void country::setPopulation(long P)
{
	population = P;
}

void country::setArea(double A)
{
	area = A;
}

string country::getCountryName() const
{
	return countryName;
}

long country::getPopulation() const
{
	return population;
}

double country::getArea() const
{
	return area;
}

double country::calcDensity() const
{
	return population / area;
}

void country::print() const
{
	cout << "Name = " << countryName << ", Population = " << population << ", Area = "
		<< area << ", Density = " << calcDensity() << endl << endl;
}

country inputCountry()  //Prompts and accepts data, returns country object.
{
	string lN;          //local variable for the country's name
	long lP;            //local variable for the population
	double lA;          //local variable for the area

	cout << "Please enter the name of the country: ";
	cin.clear(); //clears the input buffer prior to accepting input.
	cin >> lN;
	cout << "Please enter the population of this country as a whole number: ";
	cin >> lP;
	cout << "Please enter the area of this country in square kilometers: ";
	cin >> lA;

	country lCountry(lN, lP, lA);
	return lCountry;
}

country comparePopulation(country country1, country country2)
{
	if (country1.getArea() > country2.getArea())
		return country1;
	else
		return country2;
}

country compareArea(country country1, country country2)
{
	if (country1.getArea() > country2.getArea())
		return country1;
	else
		return country2;
}

country compareDensity(country country1, country country2)
{
	if (country1.calcDensity() > country2.calcDensity())
		return country1;
	else
		return country2;
}

void printLargest(country lPop, country lArea, country lDen)
{
	cout << "The country with the largest population is " << lPop.getCountryName()
		<< " - Population: " << lPop.getPopulation() << endl;;
	cout << "The country with the largest area is " << lArea.getCountryName()
		<< " - Area: " << lArea.getArea() << endl;
	cout << "The country with the highest population density is " << lDen.getCountryName()
		<< " - Density: " << lDen.calcDensity() << endl;
}
int main()
{
	country largestArea, largestPopulation, highestDensity;

	vector <country> myCountry(5);   //A vector with 5 cells of class country.

	for (int i = 0; i < myCountry.size(); i++) //For loop to cycle through the vector
	{
		myCountry[i] = inputCountry();
		if (i == 0)
		{
			largestPopulation = myCountry[i];
			printLargest(largestPopulation, largestArea, highestDensity);
		}
		else
		{
			largestPopulation = comparePopulation(largestPopulation, myCountry[i]);
			largestArea = compareArea(largestArea, myCountry[i]);
			highestDensity = compareDensity(highestDensity, myCountry[i]);
			printLargest(largestPopulation, largestArea, highestDensity);
		}

	}
	cout << "Bye!\n";

	system("PAUSE");
	return 0;
}

