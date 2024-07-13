# Templated C++ List Class
## Cloning Repository
To clone the repository: `https://github.com/helghast098/CPP-List.git`
## Repository Structure
The repository has the following file structure:

```bash
| README.md (This File)
├── CPP-List
│   │
│   ├── include # Header file of List
│   │   └── List.hpp # Contains templated List Class declaration and function definitions
│   │  
│   ├── tests # Contains test files for List class
│   │   └── test.cpp # Test file that uses gtest to test the various methods of the List Class
│   │
│   ├── CMakeLists.txt
│   │
│   └── LICENSE
└──

```
**How to build for testing:**<br>
`Using cmake:`
Create a directory named build in the main project directory. On a terminal navigate to build and type `cmake ..` then `make`. The test file can be run with the command `./ListTest` or using `ctest`.
