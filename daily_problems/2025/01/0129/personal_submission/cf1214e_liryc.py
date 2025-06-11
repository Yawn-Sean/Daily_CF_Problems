'''
https://codeforces.com/problemset/submission/1214/303465507
'''
# 关键：按距离从大到小排序
def solve(n: int, da: list[int]) -> list[str]:
    ans = []
    a = list(sorted(range(0, 2 * n, 2), key = lambda i: -da[i // 2]))
    for x, y in pairwise(a):
        ans.append(f"{x + 1} {y + 1}")
    for i in range(n):
        u, v = a[i], a[i] + 1
        d = da[u // 2]
        if i + d >= len(a):
            a.append(v)
        ans.append(f"{v + 1} {a[i + d - 1] + 1}")
    return ans