#include <iostream>
#include <string>

using namespace std;

int CalculateNbWeeks(int FirstdayPos, int nbdays)
{
	int nbWeeks{0};
	for (int  i = 0; i < nbdays; i++)
	{
		if (FirstdayPos == 7)
		{
			nbWeeks += 1;
			FirstdayPos = 1;
		}
		FirstdayPos++;
	}
	return nbWeeks;
}

int main()
{
	int imonth, ifirstpos;
	cin >> imonth;
	cin >> ifirstpos;
	int totaldays = 365;
	if (imonth > 12 || imonth < 1)
	{
		cout << "input error";
		return -1;
	}
	if (ifirstpos > 7 || ifirstpos < 1)
	{
		cout << "input error";
		return -1;
	}
	
	if (imonth % 2 != 0)
	{
		int nbdays = 31;		
		cout<< CalculateNbWeeks(ifirstpos, nbdays);
	}
	else if (imonth == 2)
	{
		int nbdays = 28;
		cout << CalculateNbWeeks(ifirstpos, nbdays);
	}
	else
	{
		int nbdays = 30;
		cout << CalculateNbWeeks(ifirstpos, nbdays);
	}
	return 0;
}