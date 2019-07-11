# cpp-csv
by cheenar

# license 
please don't sue. mission critical code should use python-csv libraries. 

# demos
honestly, I don't understand why some people have scrolls of useless information. I'm here for some short examples that let me integrate a csv parser into my program. 

### Read CSV File
```
CSVReader reader();
reader.setDelimiter(',')
reader.setMarker('"')

CSV csv = reader.parse(file_name);
CSV csv = reader.parse(file_data);

csv.lines() // a vector<Data> 
//The Data class is just a wrapper for the inner vector<string> object. You can think of it to be an extension of a vector<string> that allows
a named access of .at(index) with .column()

csv.line(0).asString();

cout << csv.line(0) // you can cout a Data object 

csv.line(0).column(0).set(value)
csv.line(0).column(0).get()

csv.columns() // a vector<vector<string>>

```

### Write CSV File
```
CSVWriter writer;
writer.setDelimiter(',')
writer.setMarker('"')

CSV file;
file.setSchema("name,age,friend");
file.line(0).set("david,12,alec");

writer.write(file);
```
