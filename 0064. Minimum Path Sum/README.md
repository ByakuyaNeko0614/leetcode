# Minimum Path Sum (Medium)

[Link to LeetCode](https://leetcode.com/problems/minimum-path-sum/submissions/2164941281/)

## Problem

Given an `m x n` `grid` filled with non-negative numbers, find a path from the top-left corner to the bottom-right corner that minimizes the sum of all numbers along the path.

You can only move **down** or **right** at any point.

### Constraints

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 200`
* `0 <= grid[i][j] <= 200`

## Thinking Process

I used **Dynamic Programming (DP)** to solve this problem.

First, I calculate the minimum path sum for the first column by adding each cell to the minimum path sum of the cell above it:

```text
grid[i][0] += grid[i-1][0]
```

Similarly, for the first row, I add each cell to the cell on its left:

```text
grid[0][j] += grid[0][j-1]
```

For every other cell, there are only two possible ways to reach it:

* From the cell above: `grid[i-1][j]`
* From the cell on the left: `grid[i][j-1]`

Therefore, I choose the smaller one and add it to the current cell:

```text
grid[i][j] += min(grid[i-1][j], grid[i][j-1])
```

After processing the entire grid, `grid[m-1][n-1]` contains the minimum path sum, so it is the answer.

## Complexity

* **Time:** `O(m * n)`
* **Space:** `O(1)` — the input `grid` is modified in place.
