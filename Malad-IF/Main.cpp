
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
#include "AttributDouble.h"
#include "AttributId.h"
#include "AttributString.h"
#include "ValeurId.h"
#include "ValeurDouble.h"
#include "ValeurString.h"
#include "GestionMaladies.h"

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

vector<vector<string>> readValues(string filename, int fieldCount, bool skipFirstLine)
{
	ifstream fs;

	vector<vector<string>> fileList;

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
	lineFields.clear();

	string currentLine;

	string currentElement;




//	 https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
	while (fs)
	{
		while (getline(fs, currentLine, '\r'))
		{
			stringstream currentLineStream(currentLine);



			while (getline(currentLineStream, currentElement, ';'))
				lineFields.push_back(currentElement);


			fileList.push_back(lineFields);

			getline(fs, currentLine);
			lineFields.clear();
		}
	}

	return fileList;
}



int oldmain()
{
	vector<pair<string, string>> desc = readDescription("HealthMeasurementDescription.txt", true);
	vector<vector<string>> vals = readValues("HealthMeasurementsWithLabels.txt", desc.size() + 1 /* disease */, true);


	vector<Attribut*> attributs;



	for (pair<string, string>& paire : desc)
	{
		if (paire.second == "double")
			attributs.push_back(new AttributDouble(paire.first));
		else if (paire.second == "ID")
			attributs.push_back(new AttributId(paire.first));
		else if (paire.second == "string")
			attributs.push_back(new AttributString(paire.first));
	}




	list<list<Valeur*>> empreintes;

	for (vector<string> vec : vals)
	{
		list<Valeur*> em;

		for (unsigned int i = 0; i < attributs.size(); i++)
			em.push_back(attributs[i]->creerValeur(vec[i]));


		empreintes.push_back(em);
		em.empty();
	}

	cout << empreintes.size() << " empreintes trouvées :" << endl;

	unsigned int i;

	for (list<Valeur*> em : empreintes)
	{
		int at = 0;
		for (Valeur* valeur : em)
		{

			// https://stackoverflow.com/questions/500493/c-equivalent-of-instanceof
			if(ValeurDouble* vd = dynamic_cast<ValeurDouble*>(valeur))
			{
				cout << attributs[at]->getNom() << "=" <<  *((double*) (vd->getValeur())) << endl;
			}

			if(ValeurId* vi = dynamic_cast<ValeurId*>(valeur))
			{
				cout << attributs[at]->getNom() << "=" << *((unsigned int*) (vi->getValeur())) << " : " << endl;
			}

			if(ValeurString* vs = dynamic_cast<ValeurString*>(valeur))
			{
				cout << attributs[at]->getNom() << "=" <<  *((string*) (vs->getValeur())) << endl;
			}

			at++;
		}
		i++;
	}

	return 0;
}


int main()
{
	GestionMaladies gm;
	gm.initialiserApplication("HealthMeasurementDescription.txt", "HealthMeasurementsWithLabels.txt");
	list<string> maladies = gm.listerMaladies();

	for (string m : maladies)
		if (!m.empty())
		cout << "Maladie trouvée : " << m << endl;



}
