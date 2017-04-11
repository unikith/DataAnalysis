#ifndef DATAANALYSIS_H
#define DATAANALYSIS_H

#define LINE_SIZE 100

#include "BST.h"

#include <fstream>

using std::ifstream;

class DataAnalysis
{
public:
	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	bool openFile();
	void closeFile();
	bool readLine(string &readData, int& readUnits, string& readTransaction);
	void readFile();
	void insertData(const string & newData, const int & newUnits, const string & transaction);
	void printTrends();
};


#endif // !DATAANALYSIS_H

