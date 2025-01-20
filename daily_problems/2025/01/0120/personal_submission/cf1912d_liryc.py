'''
https://codeforces.com/problemset/submission/1912/302043085
1912D
2025/01/20 Y2
1900
Math
'''
def solve(b: int, n: int) -> list[int]:
    c = 1
    for i in range(1, n + 1):
        c = c * b % n
        if c == 0:
            return [1, i]
        if c == 1:
            return [2, i]
        if c == n - 1:
            return [3, i]
    return [0]
