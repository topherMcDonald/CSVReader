#pragma once
#include <string>
#include <vector>
using namespace std;

class CSVReader
{
public:
	CSVReader();
	~CSVReader();
	void LoadCSV(string fileName);
	void DestroyContents();
	string getItem(int x, int y);
	int numberOfRows();
	int numberOfColumns();

private:
	vector< vector<string> > _data;

};

