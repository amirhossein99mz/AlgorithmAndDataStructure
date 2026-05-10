# stringToListOfList.c

This program separates a string into:
- substrings of letters
- substrings of digits

The substrings are stored in two circular doubly linked lists.

Example:

Input:
abc1234xyz233fgew

Output:
Letters -> abc xyz fgew
Digits  -> 1234 233

## Compile

gcc stringToListOfList.c -o output

## Run

./output
