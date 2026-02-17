'''
https://codeforces.com/contest/2195/submission/363398698
'''
# tree dp
def solve(n: int, tg: list[list[int]]):
    MOD = 1000000007
    po = [1]
    for u in po:
        for v in tg[u]:
            po.append(v)
    b = [0] * (n + 1)
    for u in po[::-1]:
        for v in tg[u]:
            b[u] = (b[u] + b[v] + 2) % MOD
    a = [0] * (n + 1)
    a[1] = (b[1] + 1) % MOD
    for u in po:
        for v in tg[u]:
            a[v] = (b[v] + a[u] + 1) % MOD
    return a[1:]
