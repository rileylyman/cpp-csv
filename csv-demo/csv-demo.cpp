#include <iostream>
#include <csv.h>

using namespace std;
using namespace csv;

int main()
{
	CSV csv;
	csv.setSchema("Name,Age,Friend");
	csv.insert_data("David,13,Alec");
	csv.insert_data("David,13,Alec");
	csv.insert_data("David,13,Alec");
	
	vector<vector<string>> cols;
	csv.columns(cols);
}
