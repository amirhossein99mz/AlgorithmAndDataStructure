# Max Triplet Product

## Problem
Find the maximum product of any three distinct elements in an array.

## Key Insight
The maximum product can come from:
1. The three largest numbers
2. OR two smallest (negative) numbers and the largest number

## Approach
- Track top 3 maximum values
- Track bottom 2 minimum values
- Compute both possible products and return the maximum

## Complexity
Time: O(n)
Space: O(1)

## Example
Input: {-10, -3, 5, 6, -2}
Output: 180
Explanation: (-10) * (-3) * 6 = 180
