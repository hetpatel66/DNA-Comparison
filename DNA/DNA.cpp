#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream inFile;
	string line;
	string a;
	string d;
	vector<string> dna;
	vector<string> names;

    const string INPUT_FILE_NAME = "234pt2.txt";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);

	inFile.open(INPUT_FILE_NAME);
	if (!inFile.is_open())
		cout << "Error: unable to open file '"
		<< INPUT_FILE_NAME << "'." << endl << endl;
	else
	{
		cout << "Reading lines from file '" << INPUT_FILE_NAME
			<< "' ..." << endl << endl;
		
		getline(inFile, line);
		line.erase(0, 3);
		cout << line << endl << endl << endl;
		inFile >> d;
		names.push_back(d);
		while (inFile.good())
		{
			inFile >> a;
			dna.push_back(a);
			inFile >> d;
			names.push_back(d);
		}
	}

	string original;
	string test;
	int x = 0;
	while (x < names.size() - 2)
	{
		cout << left << setw(16) << names[x];
		original = dna[x];
		bool match = false;
		for (int z = 0; z < original.size(); z++)
		{
			match = false;
			if (original.at(z) != 45)
			{
				for (int y = 1; y < 12; y++)
				{
					test = dna[x + y];
					if (test.at(z) + 32 == original.at(z) || test.at(z) == original.at(z))
					{
						match = true;
						break;
					}
				}
			}

			if (match == false)
			{
				cout << original.at(z);
			}
			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
				cout << original.at(z);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			}
		}

		cout << endl;

		for (int y = 1; y < 12; y++)
		{
			test = dna[x+y];
			cout << left << setw(16) << names[x+y];
			for (int z = 0; z < original.size(); z++)
			{
				if (original.at(z) == '-' || test.at(z) == '-')
				{
					cout << test.at(z);
				}
				else
				{
					if (test.at(z) + 32 == original.at(z) || test.at(z) == original.at(z))
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN); //112
						cout << test.at(z);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN); //7
					}
					else {
						cout << test.at(z);
					}
				}
			}
			cout << endl;
		}
		cout << endl << endl;
		x = x + 12;
	}

	// Close input file
	inFile.close();

    return 0;
}

