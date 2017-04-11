#ifndef DATAANALYSIS_H
#define DATAANALYSIS_H

#define LINE_SIZE 100 // used for reading from files

#include "BST.h"

#include <fstream>

using std::ifstream;

class DataAnalysis // analyzes purchase and sale information
{
public:
	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	// helper functions for run analysis
	bool openFile(); // opens file and returns success
	void closeFile(); // closes file
	bool readLine(string &readData, int& readUnits, string& readTransaction); // reads in a single line 
																			//and extracts useful data
	void readFile(); // reads entire file and prints out trees in order
	void insertData(const string & newData, const int & newUnits, const string & transaction); //inserts data into proper tree
	void printTrends(); // prints high and low for both trees
};


#endif // !DATAANALYSIS_H

