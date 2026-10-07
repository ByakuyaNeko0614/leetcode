# Trapping Rain Water (Hard)

[Link to LeetCode](https://leetcode.com/problems/trapping-rain-water/submissions/2165264839/)

## Problem

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

### Constraints

`n == height.length`

`1 <= n <= 2 * 10^4`

`0 <= height[i] <= 10^5`

## Thinking Process

I used **Two Pointers** to solve this problem.

I declared four variables: `start`, `end`, `leftMax` and `rightMax`.

The loop continues as long as start < end.

We need to find the maximum of leftMax and rightMax by:
```text
leftMax = max(height[start], leftMax);
```

```text
rightMax = max(height[end], rightMax);
```

Next, we compare `leftMax` with `rightMax` to find which one is larger.

If `leftMax` is the smaller boundary, we calculate:
```text
ans += leftMax - height[start]
```

Then, increment `start` by 1.

Otherwise, we calculate:
```text
ans += rightMax - height[end]
```

Then, decrease `end` by 1.

Finally, when the loop terminates, `ans` contains the total trapped water.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(1)`
