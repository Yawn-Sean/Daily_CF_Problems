'''
https://codeforces.com/problemset/submission/180/302248860
'''
# 二分
def solve(n: int, m: int, k: int, a: list[int]) -> int:
    def check(x):
        nonlocal m, k, a
        OK, FAIL = 0, 1
        cn = [0] * (m + 1)
        i = 0
        for j, c in enumerate(a):
            if j - i == x + k:
                cn[a[i]] -= 1
                i += 1
            cn[c] += 1
            if cn[c] == x:
                return OK
        return FAIL
    return bisect_right(range(n + 1), 0, key=check) - 1
