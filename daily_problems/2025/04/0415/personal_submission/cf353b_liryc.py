'''
https://codeforces.com/problemset/submission/353/315656605
'''
def solve(n: int, a: list[int]) -> tuple[int, list[int]]:
    cn = [0] * 100
    for x in a:
        cn[x] += 1
    sa = sorted(range(n << 1), key=lambda i: (cn[a[i]], a[i]))

    ans = [2] * (n << 1)
    for i in range(1, n << 1, 2):
        ans[sa[i]] = 1
    s1, s2 = set(), set()
    for j, i in enumerate(sa):
        if j & 1:
            s2.add(a[i])
        else:
            s1.add(a[i])
    return len(s1) * len(s2), ans
