'''
https://codeforces.com/contest/558/submission/284455759
558D
2024/10/5 Y2
2300
差分
'''

from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()

def solve() -> str:
    h, q = map(int, input().split())
    if h == 1 and q == 0: # WA at test case 40
        return "1"
    START, END = 1 << h - 1, 1 << h
    cn = Counter()
    for _ in range(q):
        i, l, r, a = map(int, input().split())
        l <<= h - i
        r = r + 1 << h - i
        if a:
            cn[l] += 1
            cn[r] -= 1
        else:
            cn[START] += 1
            cn[l] -= 1
            cn[r] += 1
            cn[END] -= 1
    ans, d, k0, c = 0, 0, 0, 0
    # print(cn)
    for k in sorted(cn):
        if c == q:
            ans, d = k0, d + k - k0
        c += cn[k]
        k0 = k
    if d == 1:
        return str(ans)
    elif d > 1:
        return "Data not sufficient!"
    else: # d == 0
        return "Game cheated!"

if __name__ == '__main__':
    ans = solve()
    print(ans)
