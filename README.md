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

csv.columns()
csv.lines()

csv.column(0)
csv.column("name")

csv.line(0).string();

csv.line(0).column(0).set(value)
csv.line(0).column(0).get()

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
