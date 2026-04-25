# Minimum Recharging Cost

## Problem
Reach distance M with battery range R, minimizing total recharge cost.

## Idea
Greedy strategy:
At each step, choose the cheapest station reachable within range.

## Steps
1. Start at position 0
2. While destination not reachable:
   - Find cheapest reachable station
   - Move there and add cost
3. If no station reachable → impossible

## Complexity
Time: O(n^2)
Space: O(1)

## Note
This greedy works for simplified scenarios. More complex cases may require DP.
