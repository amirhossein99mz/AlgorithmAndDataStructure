# Maximize Sensor Coverage

## Problem
Select the minimum number of sensors (rows) so that all cells (columns) are covered.

## Idea
This is a combinatorial search problem (set cover variant).

## Approach
- Try combinations of size k = 1..r
- For each combination, check if all columns are covered
- Stop at the first valid (minimum) solution

## Functions
- is_covered: checks coverage
- backtrack: generates combinations
- maximize_sensor_coverage: main logic

## Complexity
Exponential in worst case (subset search)

## Example
Find smallest subset of rows covering all columns.
