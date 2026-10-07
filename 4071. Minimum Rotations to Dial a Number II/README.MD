# Minimum Rotations to Dial a Number II (Medium)
[Link to LeetCode](https://leetcode.com/problems/minimum-rotations-to-dial-a-number-ii/submissions/2161691396/)

## Problem

You are given an integer n and a string s of length n consisting of digits.

The dial contains the digits 0 through 9 in order and is circular, so 0 and 9 are adjacent. The pointer initially points to 0.

To dial each digit of s in order, rotate the pointer until it points to that digit. Each rotation moves the pointer to an adjacent digit, and you may rotate in either direction. Dialing a digit that the pointer already points to requires no rotations.

Before dialing, you may perform the following operation at most once:

Choose an index k such that 0 <= k < n and reverse the suffix s[k..n - 1].
Return the minimum total number of rotations needed to dial the string after optimally choosing whether to perform the operation and which suffix to reverse.

### Constraints:

`1 <= n == s.length <= 10⁵​​​​​​​`

`s` consists only of digits `'0'` to `'9'`

## Thinking Process

### First Attempt — Brute Force

At first, I tried every possible suffix reversal.

For each position, I copied the string, reversed the suffix, and calculated the total rotation cost again.

```cpp
string newString = s;
reverse(newString.begin()+i, newString.end());
```

However, this resulted in **Memory Limit Exceeded**.

### Second Attempt — Dynamic Programming

I then tried to avoid creating a new string by modifying a vector instead.

```cpp
vector<char> dp(s.begin(), s.end());
reverse(dp.begin(), dp.end());
```

```cpp
dp[i] = s[i];
for(int j = i+1; j < n; j++){
  dp[j] = s[n-1-(j-(i+1))];
}
```

However, I still calculated the cost of almost the entire string for every possible reversal, which resulted in **Time Limit Exceeded**.

### Final Approach

Then I realized that I don't actually need to perform the reversal.

For example:

```text
Original:  a → b → c → d → e
Reversed:  a → b → e → d → c
```

The transitions inside the reversed suffix are simply reversed.

Since the dial is circular:

```text
distance(a, b) == distance(b, a)
```

their costs remain the same.

Therefore, the only cost that changes is the transition **into the reversed suffix**.

For each `i`, I only need to replace:

```text
previous → s[i]
```

with:

```text
previous → s[n - 1]
```

So:

```text
new cost = original cost - old transition + new transition
```

This reduces the solution from `O(n²)` to `O(n)`.

## Complexity

* Time: `O(n)`
* Space: `O(1)`
