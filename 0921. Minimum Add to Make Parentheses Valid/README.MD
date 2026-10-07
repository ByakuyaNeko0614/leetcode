# Minimum Add to Make Parentheses Valid (Medium)
[Link](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/2164437688/)

## Problem

A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

### Constraints:

`1 <= s.length <= 1000`
`s[i]` is either `'('` or `')'`.

## Thinking Process

I use a variable `depth` to keep track of the number of unmatched `'('`.

If `s[i] == '('`, increase `depth` by 1.


If `s[i] == ')'`:
- If `depth > 0`, match it with a existing `'('`, so `depth` decrease by 1.
- Otherwise, there is no `'('` to match it, increase `ans` by 1.

After going through the whole string, if `depth > 0`, there are still unmatched `'('`, so the final answer is:

`ans + depth`.

## Complexity

* Time: `O(n)`
* Space: `O(1)`
