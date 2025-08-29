'''
https://codeforces.com/problemset/submission/201/336080800
'''
def solve(x: int) -> int:
    if x == 3:
        return 5
    return bisect_left(range(1, 101, 2), True, key=lambda n: n * n + 1 >= x << 1) << 1 | 1
