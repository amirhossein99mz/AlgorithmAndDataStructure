# Sparse Matrix Transpose — C Implementation

A project I built to represent a sparse matrix as a linked list of lists and compute its transpose efficiently.

## How It Works
The matrix is stored in a two-level linked list: the primary list (`list_t1`) tracks rows, and each row node owns a secondary list (`list_t2`) of non-zero elements with their column index and value.

To transpose, the structure is first expanded into a temporary 100×100 dense array (unused cells set to -1), then re-read with rows and columns swapped to rebuild the linked structure.

## Data Structures
- `list_t2` — node storing a matrix value, its column index, and a `next` pointer
- `list_t1` — node storing a row index, a pointer to its `list_t2` chain, and a `next` pointer

## Key Functions
- `create(key)` — allocates a new `list_t2` node
- `insert(head, key)` — inserts a value in sorted order into a `list_t2`
- `createList1(head)` — wraps a `list_t2` chain in a new `list_t1` row node
- `free_list2 / free_list1` — memory cleanup for both list levels
- `transpose(head, head2)` — builds the transposed sparse structure into `*head2`

## Files
- `main.c` — full sparse implementation + demo `main()`
- `dense_transpose.c` — standalone dense matrix transpose helper
- `CMakeLists.txt` — CLion / CMake build config

## Build & Run
```bash
mkdir build && cd build
cmake ..
make
./SparseTranspose
```

## Notes
- Matrix size capped at 100×100 by the internal dense buffer
- Standard C only — no external dependencies
