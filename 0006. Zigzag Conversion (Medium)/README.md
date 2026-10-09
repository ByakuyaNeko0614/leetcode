# Trapping Rain Water (Hard)

[Link to LeetCode](https://leetcode.com/problems/zigzag-conversion/submissions/2165844652/)

## Problem

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
```text
P   A   H   N
A P L S I I G
Y   I   R```
And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:
```text
string convert(string s, int numRows);
```
### Constraints

`1 <= s.length <= 1000`

`s` consists of English letters (lower-case and upper-case), `','` and `'.'`.

`1 <= numRows <= 1000`

## Thinking Process

To simulate the zigzag pattern row by row, I use a `vector<string> formatting(numRows)` to represent each row of zigzag structure and process the string `s` using a combination by loops:

1. Outer Loop:

- Controls the interations through the string `s` with an index `i`
- The loop continues as long as $i < n$(where `n` is length of `s`), ensures we dont access out-of-bound characters.

2. First Inner Loop (Moving Downwards):

- Iterates through the rows from index `0` down to `numRows - 1`
- In each step, if $i < n$, it appends the current character $s[i]$ to `formatting[j]` and increments $i$ by $1$.

3. Second Inner Loop (Moving Upwards Diagonally):
- Iterates backwards through the inner rows from index `numRows - 2` up to `1` (excluding the top and bottom boundary rows).
- In each step, if $i < n$, it appends the character $s[i]$ to `formatting[j]` and increments $i$ by $1$

Concatenation:
- Finally, iterate through all rows in formatting from `0` to `numRows - 1` and concatenate their contents into a single result string ans.

## Complexity

* **Time:** $O(N)$
* **Space:** $O(N)$
