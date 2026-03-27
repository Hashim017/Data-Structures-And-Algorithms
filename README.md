# Data Structures and Algorithms

A comprehensive C++ repository demonstrating advanced data structures, algorithm implementations, and practical applications. Features capstone projects (DOS Shell and Mini Excel) showcasing real-world use of DSA concepts with complete system architecture.

## Repository Structure

### DSA-MainProjects - Flagship Implementations

#### 🖥️ DOS Shell
A complete command-line shell implementation featuring:
- File system navigation and operations
- Command parsing and execution engine
- Directory management and traversal
- File manipulation commands
- Input/output redirection
- Command history and recall
- Pipe functionality
- Permission and ownership systems
- Advanced string parsing using data structures

#### 📊 Mini Excel
A spreadsheet application demonstrating:
- 2D array-based data storage
- Cell operations and calculations
- Formula evaluation and parsing
- Data serialization and file I/O
- Cell formatting and styling
- Row and column manipulation
- Statistical functions
- Advanced data structure usage

### DSA-Weeks - Progressive Learning
- Weekly algorithm implementations
- Data structure exercises
- Complexity analysis and optimization
- Real-world problem solving

## Core Data Structures Covered

### Linear Structures
✓ **Arrays** - Dynamic arrays, 2D arrays
✓ **Linked Lists** - Singly/Doubly/Circular lists
✓ **Stacks** - LIFO, applications
✓ **Queues** - FIFO, Priority queues, Deques

### Non-Linear Structures
✓ **Trees** - Binary trees, BST, AVL, Heaps
✓ **Graphs** - Adjacency lists, Adjacency matrix
✓ **Hash Tables** - Hashing, Collision handling
✓ **Tries** - String searching and matching

### Advanced Structures
✓ **Balanced Trees** - AVL, Red-Black trees
✓ **Segment Trees** - Range queries
✓ **Disjoint Set Union** - Union-find operations
✓ **Skip Lists** - Probabilistic balanced structures

## Core Algorithms Covered

### Sorting Algorithms
- Bubble, Selection, Insertion
- Merge, Quick, Heap Sort
- Counting, Radix Sort
- Stability and analysis

### Searching Algorithms
- Linear Search
- Binary Search
- Interpolation Search
- Advanced searching techniques

### Graph Algorithms
- BFS, DFS, Topological Sort
- Dijkstra, Bellman-Ford, Floyd-Warshall
- Minimum Spanning Tree (Kruskal, Prim)
- Network flow algorithms

### Dynamic Programming
- Fibonacci, LCS, Knapsack
- Coin Change, Edit Distance
- Matrix Chain Multiplication
- Shortest Path problems

### String Algorithms
- Pattern Matching (KMP, Rabin-Karp)
- String Hashing
- Trie-based searching
- Regular expressions

## Tech Stack
- **Language:** C++ (100%)
- **Standard:** C++11 or higher
- **Compiler:** GCC/Clang
- **Build System:** Make/CMake
- **IDE:** Visual Studio, Code::Blocks, CLion

## Project Features

### DOS Shell
- Real operating system shell simulation
- Complete command interpreter
- File system operations
- Advanced process management
- Stream redirection
- Script execution

### Mini Excel
- Full spreadsheet functionality
- Mathematical and statistical operations
- Cell references and formulas
- File format support (CSV, custom format)
- Performance-optimized cell storage
- Advanced data analysis

## Learning Outcomes
✓ Master all fundamental data structures
✓ Implement sorting and searching algorithms
✓ Solve graph problems efficiently
✓ Apply dynamic programming techniques
✓ Optimize algorithm complexity
✓ Build real-world applications
✓ Analyze time and space complexity
✓ Practical system design

## Requirements
- C++11 compatible compiler
- Standard C++ library
- Terminal/Command line
- 50MB+ disk space for all projects

## Project Complexity Progression
Beginner - Basic arrays and linked lists
Intermediate - Trees, graphs, sorting
Advanced - Complex algorithms, optimization
Expert - System-level applications (DOS Shell, Mini Excel)
Performance Benchmarks
All implementations include:

## Time complexity analysis
Space complexity calculation
Performance optimization tips
Comparison with alternatives

## Code Quality Standards
Clean, readable code
Comprehensive comments
Following C++ best practices
Memory management (no leaks)
Error handling
Modular architecture

## License: MIT

## Building Projects

### Using CMake
```bash
mkdir build
cd build
cmake ..
make```
### Compile Individual Projects
```bash
# DOS Shell
g++ -std=c++11 -o dos_shell dos_shell.cpp
./dos_shell

# Mini Excel
g++ -std=c++11 -o mini_excel mini_excel.cpp
./mini_excel
