#include "pch.h"
#include "csv.h"

namespace csv {

	Data::Data(vector<string> schema, int schema_len) {
		this->schema = schema;
		this->schema_len = schema_len;
		for (int i = 0; i < schema_len; i++) {
			this->data.push_back(""); // init data with ""
		}
	}

	void Data::setData(vector<string> data) {
		this->data = data;
	}

	string Data::asString() {
		string val;
		int i = 0;
		for (i = 0; i < schema_len - 1; i++) {
			val += column(i);
			val += ", ";
		}
		val += column(i);
		return val;
	}

	string& Data::column(int index) {
		if (index < 0) { // adds pythonic style indexing
			index = schema_len + index;
		}
		if (index >= schema_len) { // adds pythonic style indexing
			index = index % schema_len;
		}
		return this->data[index];
	}

	ostream& operator<<(ostream& stream, Data& data) {
		return stream << data.asString();
	}

	CSV::CSV() {
		StringUtils::msg_warning("Set Schema!");
	}

	CSV::CSV(string schema) {
		setSchema(schema);
	}

	void CSV::setSchema(string scheme) {
		vector<string> tokens = *StringUtils::str_tok(scheme, ",");
		this->schema = tokens;
		this->schema_len = tokens.size();
	}

	void CSV::insert_data(Data& data) {
		vec_data.push_back(data);
	}

	void CSV::insert_data(string raw_data) {
		vector<string> tokens = *StringUtils::str_tok(raw_data, ",");
		if (tokens.size() != schema_len) {
			StringUtils::msg_warning("Padding Data to Fit Schema");
			for (int i = tokens.size(); i < schema_len; i++) {
				tokens.push_back("");
			}
		}
		Data data(schema, schema_len);
		data.setData(tokens);
		insert_data(data);
	}

	Data& CSV::line(int index) {
		if (index < 0) { // adds pythonic style indexing
			index = vec_data.size() + index;
		}
		if (index >= vec_data.size()) { // adds pythonic style indexing
			index = index % vec_data.size();
		}
		return vec_data[index];
	}

	vector<Data> CSV::lines() {
		return vec_data;
	}

	vector<vector<string>> CSV::columns() {
		vector<vector<string>> cols;
		for (int x = 0; x < schema_len; x++) {
			cols.push_back(vector<string>());
		}
		for (auto col : vec_data) {
			for (int i = 0; i < schema_len; i++) {
				cols[i].push_back(col.column(i));
			}
		}
		return cols;
	}

}