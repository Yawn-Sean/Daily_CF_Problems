'''
https://codeforces.com/contest/551/submission/280472028
551B
2024/9/9 Y1
1800
string, counter
'''

from collections import Counter

def init():
    a = input()
    b = input()
    c = input()
    return a, b, c

def solve(a: str, b: str, c: str) -> str:
    ca, cb, cc = Counter(a), Counter(b), Counter(c)
    maxb = min(ca[x] // n for x, n in cb.items())
    tmax, tb, tc = 0, 0, 0
    for nb in range(maxb + 1):
        nc = min((ca[x] - cb[x] * nb) // n for x, n in cc.items())
        if nb + nc > tmax:
            tmax, tb, tc = nb + nc, nb, nc
    ans = []
    for _ in range(tb):
        for x in b:
            ans.append(x)
            ca[x] -= 1
    for _ in range(tc):
        for x in c:
            ans.append(x)
            ca[x] -= 1
    for x, n in ca.items():
        if n:
            ans += [x] * n
    return "".join(ans)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
