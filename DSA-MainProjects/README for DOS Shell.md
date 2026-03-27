
---

## 📝 **README for DOS Shell**

```markdown
# DOS Shell - DSA Capstone Project

A complete command-line shell implementation that replicates essential DOS/Unix shell functionality. Demonstrates advanced data structure usage for command parsing, file system operations, and process management.

## Features
- **Command Execution** - Parse and execute system commands
- **Directory Navigation** - cd, pwd, ls, mkdir operations
- **File Operations** - Copy, move, delete, rename files
- **Input/Output Redirection** - Redirect stdin/stdout
- **Pipe Operations** - Chain commands with pipes
- **Command History** - Recall and repeat commands
- **Environment Variables** - Set, get, export variables
- **Path Resolution** - Locate executable files
- **Batch Processing** - Execute script files
- **Permission Management** - File access control

## Tech Stack
- **Language:** C++ (100%)
- **Data Structures:** Queues, Stacks, Linked Lists, Hash Tables
- **Algorithms:** String parsing, Pattern matching
- **Architecture:** Command interpreter pattern

## Project Structure
DOS-Shell/ ├── Core/ │ ├── Shell.cpp # Main shell loop │ ├── CommandInterpreter.cpp # Parse commands │ └── Environment.cpp # Environment variables ├── Commands/ │ ├── FileOps.cpp # File operations (cp, mv, rm) │ ├── DirectoryOps.cpp # Directory operations (cd, ls, pwd) │ ├── SystemOps.cpp # System operations │ └── CommandRegistry.cpp # Command management ├── DataStructures/ │ ├── CommandQueue.cpp # Command buffer │ ├── History.cpp # Command history │ └── PathResolver.cpp # Path resolution ├── Utilities/ │ ├── Parser.cpp # String parsing │ ├── FileSystem.cpp # File system interface │ └── Utils.cpp # Helper functions └── main.cpp


## Data Structures Used
- **Queue** - Command execution queue
- **Stack** - Directory traversal
- **Linked List** - Command history
- **Hash Table** - Environment variables and command registry
- **String Parsing** - Tokenization

## Core Functionality

### Command Processing
1. Input parsing and tokenization
2. Command validation
3. Argument processing
4. Redirection handling
5. Pipe connection
6. Execution

### File System Operations
ls - List directory contents cd - Change directory pwd - Print working directory mkdir - Create directory rm/del - Delete file/directory cp/copy - Copy file mv/move - Move/rename file cat/type - Display file content

Code

### I/O Operations
Code
      - Redirect output
< - Redirect input

Code
     - Append output
| - Pipe commands & - Background execution

Code

### System Operations
echo - Print text set - Set variables path - Show/set PATH history - Show command history exit/quit - Exit shell clear - Clear screen

Code

## Algorithms

### Command Parsing Algorithm
Tokenize input string
Identify command and arguments
Check for redirection operators
Handle pipe symbols
Expand environment variables
Validate command syntax
Code

### Directory Traversal
- Depth-first search for nested directories
- Efficient path resolution
- Symbolic link handling

### Command History
- Queue-based storage (circular buffer)
- Fast lookup using hash table
- Limited memory footprint

## System Requirements
- Windows/Linux/macOS compatible
- C++11 compiler
- Standard C++ library
- 10MB+ disk space
- Terminal/Command line interface

## Installation & Usage

### Build
```bash
g++ -std=c++11 -o dos_shell *.cpp
Run
bash
./dos_shell

## Example Session
DOS Shell> ls
Documents  Downloads  Pictures
DOS Shell> cd Documents
DOS Shell> pwd
/home/user/Documents
DOS Shell> echo "Hello" > file.txt
DOS Shell> cat file.txt
Hello
DOS Shell> exit

## Implementation Highlights

### Efficient Command Storage
Hash table for O(1) command lookup
Minimal memory overhead
Fast command execution

### Robust Parsing
Handles complex quoting
Escape sequence support
Error recovery

### Stream Management
Proper I/O redirection
Pipe buffer management
Resource cleanup

## Performance Analysis
Command Lookup: O(1) average case
Path Resolution: O(n) where n = path length
History Search: O(1) with hash table
File Operations: O(n) where n = file size

## Advanced Features
✓ Tab completion simulation ✓ Wildcard pattern matching ✓ Script file execution ✓ Multiple command chaining ✓ Conditional execution (&&, ||) ✓ Error handling and reporting ✓ Customizable prompts

## Development Highlights
✓ Professional command-line interface ✓ Efficient data structure usage ✓ Scalable architecture ✓ Comprehensive error handling ✓ Cross-platform compatibility ✓ Clean, modular code

License: MIT
Type: DSA Capstone Project
