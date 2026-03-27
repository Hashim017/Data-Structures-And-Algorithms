
---

## 📝 **README for Mini Excel**

```markdown
# Mini Excel - DSA Capstone Project

A functional spreadsheet application built entirely in C++. Demonstrates advanced data structure design, formula parsing, and efficient cell management using optimized algorithms.

## Features
- **Cell Operations** - Read, write, update cells
- **Formulas & Calculations** - Parse and evaluate expressions
- **Mathematical Functions** - SUM, AVG, MIN, MAX, COUNT
- **Cell References** - Support relative and absolute references
- **Data Types** - Numbers, strings, dates, boolean
- **Formatting** - Cell styling and number formatting
- **File I/O** - Save/load spreadsheets (CSV, custom format)
- **Range Operations** - Operate on cell ranges
- **Data Validation** - Input validation and constraints
- **Performance Optimization** - Lazy evaluation, caching

## Tech Stack
- **Language:** C++ (100%)
- **Data Structures:** 2D Arrays, Hash Tables, Trees, Stacks
- **Algorithms:** Expression parsing, Recursive evaluation
- **Architecture:** MVC pattern

## Project Structure
MiniExcel/ ├── Core/ │ ├── Spreadsheet.cpp # Main spreadsheet engine │ ├── Cell.cpp # Individual cell class │ └── Grid.cpp # 2D grid management ├── Formulas/ │ ├── Parser.cpp # Formula parsing │ ├── Evaluator.cpp # Expression evaluation │ └── Functions.cpp # Built-in functions ├── DataStructures/ │ ├── FormulaTree.cpp # Parse tree for formulas │ ├── CellCache.cpp # Computation caching │ └── DependencyGraph.cpp # Cell dependency tracking ├── FileSystem/ │ ├── FileIO.cpp # File operations │ ├── CSVHandler.cpp # CSV format support │ └── Serializer.cpp # Serialization ├── UI/ │ ├── Display.cpp # Console display │ ├── InputHandler.cpp # User input │ └── Formatter.cpp # Cell formatting └── main.cpp


## Data Structures Used
- **2D Vector/Array** - Cell storage (rows × columns)
- **Hash Table** - Named ranges and cell references
- **Stack** - Formula parsing (shunting yard algorithm)
- **Tree** - Expression tree for formula evaluation
- **Linked List** - Cell change history
- **Graph** - Dependency tracking between cells

## Core Functionality

### Cell Management
```cpp
set(row, col, value)    - Set cell value
get(row, col)           - Get cell value
delete(row, col)        - Clear cell
format(row, col, fmt)   - Apply formatting
Formula Operations
+, -, *, /              - Basic arithmetic
^, %                    - Power, modulo
SUM(range)              - Sum of cells
AVG(range)              - Average value
MIN(range), MAX(range)  - Min/max values
COUNT(range)            - Count cells
IF(condition, val1, val2) - Conditional

## File Operations
save(filename)          - Save spreadsheet
load(filename)          - Load spreadsheet
export(format)          - Export to format
import(filename)        - Import data

## Algorithms

### Formula Parsing (Shunting Yard Algorithm)
1. Tokenize formula string
2. Apply operator precedence
3. Handle parentheses
4. Build expression tree
5. Evaluate tree recursively

### Cell Dependency Resolution
1. Build dependency graph
2. Topological sort cells
3. Detect circular references
4. Update in correct order
5. Cache results

### Range Evaluation
1. Parse range notation (A1:B5)
2. Iterate through cells
3. Apply function to each
4. Aggregate results
5. Return computed value

## System Requirements
C++11 compiler
Standard C++ library
100MB+ disk space
RAM: 256MB+
Terminal/Console

## Installation & Usage

### Build
g++ -std=c++11 -o mini_excel *.cpp

### Run
./mini_excel

## Example Session
Mini Excel> set 1 1 100
Cell (1,1) = 100

Mini Excel> set 1 2 200
Cell (1,2) = 200

Mini Excel> set 1 3 =SUM(1:1,1:2)
Cell (1,3) = 300

Mini Excel> get 1 3
300

Mini Excel> save mysheet.csv
Spreadsheet saved

Mini Excel> exit

## Implementation Highlights

### Efficient Cell Storage
2D vector for contiguous memory
Hash table for named cells
Minimal overhead per cell

### Formula Evaluation
Recursive descent parsing
Operator precedence handling
Function dispatch table
Error recovery

### Performance Optimization
Lazy evaluation (calculate only when needed)
Result caching
Incremental updates
Circular reference detection

## Advanced Features
✓ Multi-cell operations ✓ Named ranges support ✓ Cell validation rules ✓ Conditional formatting ✓ Formula auditing ✓ Change tracking ✓ Undo/Redo operations ✓ Data sorting and filtering

## Formula Examples
=A1+B1              - Cell reference
=SUM(A1:A10)        - Range sum
=AVG(B1:B5)         - Average
=IF(A1>100,"High","Low") - Conditional
=COUNT(A:A)         - Count non-empty cells
=(A1+B1)*C1         - Complex calculation

## Time Complexity Analysis
Cell Set/Get: O(1)
Formula Parse: O(n) where n = formula length
Formula Evaluate: O(m) where m = cells referenced
Range Operation: O(k) where k = range size
File Save: O(n*m) where n,m = dimensions

## Space Complexity
Grid Storage: O(n*m) for n×m grid
Formula Tree: O(k) for k operators
Dependency Graph: O(n*m)

## Development Highlights
✓ Advanced formula parsing and evaluation ✓ Efficient data structure design ✓ Complex algorithm implementation ✓ Circular reference detection ✓ Comprehensive error handling ✓ Production-quality code

## License: MIT

## Type: DSA Capstone Project
