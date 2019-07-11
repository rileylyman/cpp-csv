#pragma once

#include "pch.h"
#include "string_utils.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <typename T>
int indexOf(vector<T> vec, T key) {
	for (auto i = vec.begin(); i < vec.end(); i++) {
		if (vec[i] == key) {
			return i;
		}
	}
	return -1;
}

namespace csv {


	class Data {
	private:
		vector<string> schema;
		vector<string> data;
		int schema_len;
	public:
		Data(vector<string> schema, int schema_len);
		
		void setData(vector<string> data); // debug function tbh

		string& column(int index);

		friend ostream& operator<<(ostream& stream, Data& data);
	};

	class CSV {
	private:
		int schema_len;
		vector<string> schema;
		vector<Data> vec_data;
		vector<vector<string>> cols;
	public:
		CSV();
		CSV(string schema);

		void setSchema(string scheme);
		
		void insert_data(string raw_data);
		void insert_data(Data& data);

		Data& line(int index);
		vector<Data> lines();

		vector<vector<string>> columns();
	};

	class CSVReader {
	private:
	public:
	};

	class CSVWriter {
	private:
	public:
	};

}