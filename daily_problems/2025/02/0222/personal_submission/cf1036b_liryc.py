'''
https://codeforces.com/problemset/submission/1036/307216704
'''
# 分类讨论
def solve(n: int, m: int, k: int) -> int:
    min_moves = max(n, m)
    if min_moves > k:
        return -1
    if abs(n - m) & 1:
        return k - 1
    else:
        if k - min_moves & 1:
            return k - 2
        else:
            return k
