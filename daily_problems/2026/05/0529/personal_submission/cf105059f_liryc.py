'''
https://codeforces.com/gym/105059/submission/376494567
math, contributions
'''
MAXN = 200000
ps = [0.0] * (MAXN + 1)
for i in range(1, MAXN + 1):
    ps[i] = ps[i - 1] + 1.0 / i

def solve(n: int, a: list[int]) -> float:
    ss = [0.0] * (n + 1)
    for i in range(-1, -n - 1, -1):
        ss[i] = -i / (n + i + 1) + ss[i + 1]
    ans, nr = 0.0, (1 + n) * n >> 1
    for i, x in enumerate(a):
        k = min(i + 1, n - i)
        ans += x * k
        ans += x * (ps[n - k] - ps[k]) * k
        ans += x * ss[n - k + 1]
    return ans / nr

