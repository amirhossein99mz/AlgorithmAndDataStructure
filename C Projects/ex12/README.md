# List of Lists — C Implementation

A project I built to load structured text data from a file into a two-level linked list, using strings as the primary key and integers as the secondary key.

## How It Works
The program reads a file where each line contains a string and an integer. It groups entries by string into a primary linked list (`list_1`), and for each unique string, chains all associated integers into a secondary linked list (`list_2`). Duplicate entries share the same node and their integers are appended.

## Data Structures
- `list_2` — singly linked list of `int` values
- `list_1` — singly linked list of nodes, each holding a dynamic string and a pointer to a `list_2`

## Files
- `main.c` — full implementation + demo `main()`
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./ListOfLists
```

## Notes
- Strings are heap-allocated via `strdup`
- The primary list is kept in alphabetical order on insert
- All memory is freed before exit
