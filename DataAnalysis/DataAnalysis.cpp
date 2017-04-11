#include "DataAnalysis.h"
// Member Functions
// Public Functions
void DataAnalysis::runAnalysis()
{
	bool openedFile = openFile();
	if (openedFile)
	{
		readFile();
		printTrends();
		closeFile();
	}
}

// Private Functions
bool DataAnalysis::openFile()
{
	bool success = false;
	this->mCsvStream.open("data.csv");
	if (mCsvStream.is_open())
	{
		success = true;
	}

	return success;
}

void DataAnalysis::closeFile()
{
	this->mCsvStream.close();
}

bool DataAnalysis::readLine(string &readData, int& readUnits, string& readTransaction)
{
	bool success = false;
	char temp[LINE_SIZE];
	this->mCsvStream.getline(temp, LINE_SIZE, ','); // units
	if (temp[0] != '\0') // prevennts trying to token a blank line
	{
		success = true;
		readUnits = std::stoi(temp);

		this->mCsvStream.getline(temp, LINE_SIZE, ','); // Type, saved in data
		readData = temp;

		this->mCsvStream.getline(temp, LINE_SIZE); // transaction
		readTransaction = temp;
	}
	else
	{
		success = false;
	}
	return success;

}

void DataAnalysis::readFile()
{
	char temp[LINE_SIZE];
	mCsvStream.getline(temp, LINE_SIZE); // reads in header
	while (!this->mCsvStream.eof())
	{
		string data, transaction;
		int units;
		bool lineRead = readLine(data, units, transaction);
		if (lineRead) // prevents blank line from being inserted into trees
		{
			insertData(data, units, transaction);
		}
	}

	cout << endl << "Purchased" << endl;
	this->mTreePurchased.inOrderTransversal();
	cout << endl << "Sold" << endl;
	this->mTreeSold.inOrderTransversal();
}

void DataAnalysis::insertData(const string & newData, const int & newUnits, const string & transaction)
{
	if (transaction == "Purchased")
	{
		this->mTreePurchased.insert(newData, newUnits);
	}
	else if (transaction == "Sold")
	{
		this->mTreeSold.insert(newData, newUnits);
	}
	else
	{
		cout << "Invalid file format for " << newData  << " will not be included in evaluation"<< endl;
	}
}

void DataAnalysis::printTrends()
{
	cout << endl <<  "Purchased" << endl;
	cout << "Largest - ";
	this->mTreePurchased.findLargest().printData();
	cout << endl;
	cout << "Smallest - ";
	this->mTreePurchased.findSmallest().printData();
	cout << endl << endl;

	cout << "Sold" << endl;
	cout << "Largest - ";
	this->mTreeSold.findLargest().printData();
	cout << endl;
	cout << "Smallest - ";
	this->mTreeSold.findSmallest().printData();
	cout << endl;
}