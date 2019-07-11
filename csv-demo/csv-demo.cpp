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
	
	cout << csv.columns().size() << endl;
	cout << csv.columns().at(0).at(0);

	return 0;
}
