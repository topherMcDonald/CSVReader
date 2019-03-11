#include "CSVReader.h"
#include <fstream>
/*A comment*/
CSVReader::CSVReader()
{
}
CSVReader::~CSVReader()
{
}
void CSVReader::LoadCSV(string fileName)
{
	ifstream in(fileName.c_str());
	string element, delimiters = ",\n\r";
	int row = 0;
	char ch;
	_data.push_back(vector <string>());
	while (in.read((char*)&ch, 1))
	{
		if (delimiters.find_first_of(ch) == delimiters.npos)
		{
			element += ch;
		}
		else
		{
			if (ch != '\r')
			{
				_data[row].push_back(element);
				element = "";
				if (ch == '\n')
				{
					_data.push_back(vector <string>());
					row++;
				}
			}
		}
	}
	if (element.size() > 0)
		_data[row].push_back(element);
	in.close();

}
void CSVReader::DestroyContents()
{
	for (int i = 0; i < _data.size(); i++)
	{
		for (int j = 0; j < _data[i].size(); j++)
			_data[i].pop_back();
		_data.pop_back();
	}

}
string CSVReader::getItem(int x, int y)
{
	return _data[x][y];
}
int CSVReader::numberOfColumns()
{
	if (_data.size() > 0)
		return _data[0].size();
	else
		return 0;
}
int CSVReader::numberOfRows()
{
	return _data.size();
}


