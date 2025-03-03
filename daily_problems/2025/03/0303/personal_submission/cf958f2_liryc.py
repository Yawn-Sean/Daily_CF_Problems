'''
https://codeforces.com/problemset/submission/958/308735137
'''
# 滑动窗口
def solve(n: int, m: int, a: list[int], ka: list[int]) -> int:
    for i in range(n):
        a[i] -= 1
    cn = [0] * m
    km = sum(cn[i] >= ka[i] for i in range(m))
    i = 0
    minsize = n + 1
    for j in range(n):
        c = a[j]
        cn[c] += 1
        if cn[c] == ka[c]:
            km += 1
        while km >= m:
            minsize = min(minsize, j - i + 1)
            c = a[i]
            if cn[c] == ka[c]:
                km -= 1
            cn[c] -= 1
            i += 1
    return -1 if minsize > n else minsize - sum(ka)
