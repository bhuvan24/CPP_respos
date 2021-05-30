/*#######################################
##Authour:Bhuvaneswaran################
#######################################*/
///Find given list of measurement units and plurals-suffix in the given sentences
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

bool b_endswith(std::string const& input_str, std::string const& char_to_search) {
	if (input_str.length() >= char_to_search.length()) {
		return (0 == input_str.compare(input_str.length() - char_to_search.length(), char_to_search.length(), char_to_search));
	}
	else {
		return false;
	}
}
bool find_measurements_in_list(string str1, list<string> lst)
{
	list<string>::iterator it;
	bool Bfound = false;
	for (it = lst.begin(); it != lst.end(); ++it)
	{
		if (str1 == *it)
		{
			Bfound = true;
		}
		else if (b_endswith(str1, *it))
		{
			Bfound = true;
		}
	}
	return Bfound;
}

bool find_counts_in_list(string str1, list<string> lst)
{
	list<string>::iterator it;
	bool bFound = false;
	for (it = lst.begin(); it != lst.end(); ++it)
	{
		string str_to_search = *it;
		bFound = b_endswith(str1, str_to_search);
		if (bFound)
			break;
	}
	return bFound;
}
vector<string> space_tokenize(string s, string del = " ")
{
	vector<string>strvec;
	int start = 0;
	int end = s.find(del);
	while (end != -1) {
		strvec.push_back(s.substr(start, end - start));
		start = end + del.size();
		end = s.find(del, start);
	}
	strvec.push_back(s.substr(start, end - start));
	return strvec;
}
void print_val(string str, int type, int pos1, int pos2)
{
	if (type == 0)
	{
		cout << str << ",[" << pos1 << "," << pos2 << "]," << "Counts" << endl;
	}
	else if (type == 1)
	{
		cout << str << ",[" << pos1 << "," << pos2 << "]," << "Unit of Measure" << endl;
	}
}
int main()
{
	list<string> list_measurements = { "pixels","mmol/L","fl.","oz.","mm","L","km","Kg","mm/L","mole","K","m","A","kilo","cd","cubic","foot" };
	list<string> lst_plurals = { "s","s.","es","le","ves","ies","en" };
	string str;
	getline(cin, str);
	vector<string> vecstring = space_tokenize(str);
	int pos1 = -1, pos2 = -1;
	int strpos = 0;
	string strr;
	bool bflag1 = false;
	bool bflag2 = false;
	for (int i = 0; i < vecstring.size(); i++)
	{
		string str = vecstring[i];
		if (isdigit(str[0]))
		{
			if (find_measurements_in_list(vecstring[i], list_measurements))
			{
				strr = vecstring[i];
				pos1 = strpos;
				pos2 = pos1 + strr.size();
				print_val(strr, 1, pos1, pos2);
			}
			else if (find_measurements_in_list(vecstring[i + 1], list_measurements))
			{
				if (find_measurements_in_list(vecstring[i + 2], list_measurements))
				{
					strr = vecstring[i] + " " + vecstring[i + 1] + " " + vecstring[i + 2];
					pos1 = strpos;
					pos2 = pos1 + strr.size();
					print_val(strr, 1, pos1, pos2);
				}
				else
				{
					strr = vecstring[i] + " " + vecstring[i + 1];
					pos1 = strpos;
					pos2 = pos1 + strr.size();
					print_val(strr, 1, pos1, pos2);
				}
			}
			else
			{
				bflag2 = find_counts_in_list(vecstring[i + 1], lst_plurals);
				if (bflag2)
				{
					strr = vecstring[i] + " " + vecstring[i + 1];
					pos1 = strpos;
					pos2 = pos1 + strr.size();
					print_val(strr, 0, pos1, pos2);
				}
			}
		}
		strpos = strpos + str.size() + 1;
	}
	if (!bflag1 && !bflag2)
	{
		cout << "NONE" << endl;
	}

	return 0;

}
