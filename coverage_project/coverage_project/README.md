# Sensor Coverage Project

This project solves the sensor coverage exercise using C.

## Goal

Given a binary grid where each row is a sensor and each column is a cell:

- `1` means the sensor covers that cell.
- `0` means the sensor does not cover that cell.

The function finds the minimum number of sensors that cover all cells, if possible.

## Main function

```c
int maximize_sensor_coverage(int **grid, int r, int c, int *sensor, int *count);
```

## Return value

- Returns `1` if a set of sensors covering all cells exists.
- Returns `0` if no complete coverage exists.
- Returns `-1` for memory/input errors.

## Output parameters

- `sensor` stores the selected sensor indexes.
- `count` stores how many sensors are selected.

## Compile

```bash
gcc coverage.c -o coverage
```

## Run

```bash
./coverage
```

## Example output

One valid output is:

```text
Return value: 1
Selected sensors: 0 4
Count: 2
```
