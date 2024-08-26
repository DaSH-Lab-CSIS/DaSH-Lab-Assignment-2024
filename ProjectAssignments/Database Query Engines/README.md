## Task 1
Read about SQL and attempt to do as much of this assignment as possible. The answers for this assignment should be a pdf with your query for the question and a screenshot of the output.

Assignment Link: https://15445.courses.cs.cmu.edu/spring2023/homework1/
Playlist for Task 1 and Task 2: https://www.youtube.com/playlist?list=PLSE8ODhjZXjbj8BMuIrRcacnQh20hmY9g

## Task 2
Your task is to build a basic database (DB) using OOP concepts and database management system algorithms.

Define the DB as an object. Internally, the database can be represented as 2D matrix. Further add functions/methods to perform database functions such as *CREATE, ALTER, DELETE* *SELECT*, aggregate functions such as *MAX*, *SUM,* operations such as *JOIN, CROSS PRODUCT.* These functions/operations should NOT use any in built method or library. The algorithm should be coded up from scratch. Create a sample test case to showcase the working of your code. Do link/mention the algorithm used for each function as a comment above the same.

Feel free to restrict the usage of a function. For example the select statement can only select based on one condition. We want to test your understanding and implementation skills, mainly if you have understood the algorithm you have implemented and if you have implemented the algorithm correctly. Moreover, there is no need to implement numerous functions. Implementation of a few basic functions would suffice. Use of generative AI is accepatble as long as you can explain the code and justify the design choices.

Below is a basic template of how a Database object could be implemented in an Object Oriented manner.

**Python:**

```python
class Database:
  self.database = None
  self.columnToDatabaseIndexMapping = {} #maps column name with its index in the 'database' variable
  self.numColumns = 0 #keeps track of number of columns
  self.numRows = 0 #keeps track of number of rows
  self.columnsSchema = {} #maps column name with its type
  
  def __init__(self, columns: Dict, primary_key = None: str) -> None:
    self.database = []
    self.numColumns = len(columns)
    ctr = 0
    for col in columns:
        self.columnToDatabaseIndexMapping[col] = ctr
        ctr += 1

  def Select(self,column: str, conditionType = "=": str, value = None) -> Database:
    if value == None:
        return self
    elif value == "=":
        #create and return a new database object with only rows with that column value = value
    elif value == ">":
        #create and return a new database object with only rows with that column value > value
    elif value == "<":
        #create and return a new database object with only rows with that column value < value
```

**Java:**

```java
import java.util.*;

class Database {
    private List<List<Object>> database;
    private Map<String, Integer> columnToDatabaseIndexMapping; // Maps column name with its index
    private int numColumns; // Number of columns
    private int numRows; // Number of rows
    private Map<String, String> columnsSchema; // Maps column name with its type
    private String primaryKey;

    public Database(Map<String, String> columns, String primaryKey) {
        this.database = new ArrayList<>();
        this.columnToDatabaseIndexMapping = new HashMap<>();
        this.columnsSchema = new HashMap<>(columns);
        this.primaryKey = primaryKey;
        this.numColumns = columns.size();

        int ctr = 0;
        for (String col : columns.keySet()) {
            this.columnToDatabaseIndexMapping.put(col, ctr);
            ctr++;
        }
    }

    public Database Select(String column, String conditionType, Object value) {
        if (value == null) {
            return this;
        } else if (conditionType.equals("=")) {
            // Create and return a new Database object with only rows where column value = value
        } else if (conditionType.equals(">")) {
            // Create and return a new Database object with only rows where column value > value
        } else if (conditionType.equals("<")) {
            // Create and return a new Database object with only rows where column value < value
        }
        return null; // Placeholder return statement
    }
}
```

**C++**

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Database {
private:
    std::vector<std::vector<std::string>> database; // Stores the actual data
    std::unordered_map<std::string, int> columnToDatabaseIndexMapping; // Maps column name with its index
    int numColumns; // Number of columns
    int numRows; // Number of rows
    std::unordered_map<std::string, std::string> columnsSchema; // Maps column name with its type
    std::string primaryKey;

public:
    // Constructor
    Database(std::unordered_map<std::string, std::string> columns, std::string primaryKey) {
        this->numColumns = columns.size();
        this->primaryKey = primaryKey;

        int ctr = 0;
        for (const auto& col : columns) {
            columnToDatabaseIndexMapping[col.first] = ctr;
            ctr++;
        }
    }

    // Select method
    Database* Select(std::string column, std::string conditionType, std::string value = "") {
        if (value.empty()) {
            return this;
        } else if (conditionType == "=") {
            // Create and return a new Database object with only rows where column value = value
        } else if (conditionType == ">") {
            // Create and return a new Database object with only rows where column value > value
        } else if (conditionType == "<") {
            // Create and return a new Database object with only rows where column value < value
        }
        return nullptr; // Placeholder return statement
    }
};
```

## Task 3
If time permits, go through either one of these papers:
Paper 1 - Evaluation of columnar formats: https://arxiv.org/pdf/2304.05028
Paper 2 - Dremel: https://www.vldb.org/pvldb/vol13/p3461-melnik.pdf
