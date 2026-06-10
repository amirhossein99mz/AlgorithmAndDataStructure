# Evacuation Routes Project

This project contains a C program that finds and prints all valid evacuation paths
in a 2D grid representing a city. The program follows these rules:

- Movement is restricted to right or down directions only.
- The total traversal time must not exceed `max_time`.
- Blocked cells (value 0) cannot be entered.

## Files

- `evacuation.c` : C source code implementing DFS to find all valid routes.
- `README.md` : This documentation file.

## Compilation & Execution

```bash
gcc evacuation.c -o evacuation
./evacuation
```

The program prints each valid route along with its total traversal time.
