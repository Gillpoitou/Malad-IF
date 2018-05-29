
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Attribut.h"

using namespace std;



vector<pair<string, string>> readDescription(string filename, bool skipFirstLine)
{
	ifstream fs;

	vector<pair<string, string>> fileList;

	fs.open(filename.c_str());
	if (!fs)
	{
		cerr << "Error opening file : " << filename << endl;
		exit(EXIT_FAILURE);
	}
	string line;

	if (skipFirstLine)
		getline(fs, line);


	istringstream ss(line);

	pair<string, string> lineFields;
	string current;

	while (fs)
	{
		getline(fs, current, ';');
		lineFields.first = current;

		getline(fs, current, '\r'); // YAY windows shitty CRLF
		lineFields.second = current;
		getline(fs, current, '\n');

		if (lineFields.first.empty() || lineFields.second.empty())
			break;


		fileList.push_back(lineFields);

		lineFields.first.clear();
		lineFields.second.clear();
	}

	return fileList;
}

list<vector<string>> readValues(string filename, int fieldCount, bool skipFirstLine)
{
	ifstream fs;

	list<vector<string>> fileList;

	fs.open(filename.c_str());
	if (!fs)
	{
		cerr << "Error opening file : " << filename << endl;
		exit(EXIT_FAILURE);
	}
	string line;

	if (skipFirstLine)
		getline(fs, line);


	istringstream ss(line);

	vector<string> lineFields(fieldCount);
	string currentLine;

	string currentElement;

//	 https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
	while (fs)
	{
		while (getline(fs, currentLine))
		{
			stringstream currentLineStream(currentLine);

			while (getline(currentLineStream, currentElement, ';'))
				lineFields.push_back(currentElement);

			lineFields.pop_back();

//			https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string
			currentElement.erase(remove(currentElement.begin(), currentElement.end(), '\r'), currentElement.end());
			lineFields.push_back(currentElement);

			fileList.push_back(lineFields);
			lineFields.clear();
		}
	}

	return fileList;
}



int main()
{
//	string type, name;
//	HandledType *t;
//
//	cin >> type;
//	cin >> name;
//
//
//
//	if (type == "double")
//		t = new Double(name);
//
//	string v;
//	cin >> v;
//
//	Value *val = t->convert(v);
//
//	cout << *((double*) (val->value()));

	vector<pair<string, string>> desc = readDescription("HealthMeasurementDescription.txt", true);
	list<vector<string>> vals = readValues("HealthMeasurementsWithLabels.txt", desc.size() + 1 /* disease */, true);

	return 0;
}

