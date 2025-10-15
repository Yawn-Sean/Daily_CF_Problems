'''
https://codeforces.com/problemset/submission/33/332200887
'''
# 前后缀分解，枚举中间点
def solve(n: int, a: list[int]) -> int:
    pre, suf = [0] * n, [0] * n
    sm = 0
    for i in range(n):
        sm += -a[i] - a[i]
        pre[i] = max(sm, 0) if i == 0 else max(sm, pre[i - 1])
    sm = 0
    for i in range(n - 1, -1, -1):
        sm += -a[i] - a[i]
        suf[i] = max(sm, 0) if i == n - 1 else max(sm, suf[i + 1])
    return sum(a) + max(pre[i] + (0 if i == n - 1 else suf[i + 1]) for i in range(n))
