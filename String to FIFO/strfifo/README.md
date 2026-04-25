# String to Circular FIFO — C Implementation

A project I built to parse a mixed string of letters and digits into two separate circular doubly-linked FIFO lists — one collecting letter substrings, the other digit substrings.

## How It Works
The function scans the input string one character at a time. When it encounters a letter, it reads all consecutive letters into a buffer and appends the resulting substring to the letter FIFO. When it encounters a digit, it does the same for the digit FIFO. This continues until the end of the string.

Each list is circular and doubly-linked: the tail's `next` points back to the head, and the head's `prev` points to the tail. New nodes are always appended at the tail, preserving insertion order (FIFO semantics).

## Data Structure
- `node_t` — holds a heap-allocated string, a `prev` pointer, and a `next` pointer
- A single `node_t*` head pointer represents the whole circular list

## Key Functions
- `create_node(string)` — allocates a node and duplicates the string
- `insert_into_circular_linked_list(head, node)` — appends to tail of circular list
- `string_to_fifo(s, letter, digit)` — splits the string and fills both FIFOs

## Files
- `main.c` — full implementation + demo `main()`
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./StringToFifo
```

## Notes
- Standard C only — uses `<ctype.h>` for `isalpha` / `isdigit`
- Buffer capped at 100 chars per substring
