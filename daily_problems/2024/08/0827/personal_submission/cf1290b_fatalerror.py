import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
mii = lambda: map(int, input().split())
lii = lambda: list(mii())

s = input()
pres = [[0] * 26]
for ch in s:
    pres.append(pres[-1].copy())
    pres[-1][ord(ch)-97] += 1

nq = ii()
for _ in range(nq):
    l, r = mii()
    print('No' if l < r and sum(pres[r][i] - pres[l-1][i] != 0 for i in range(26)) <= 2 and s[l-1] == s[r-1] else 'Yes')