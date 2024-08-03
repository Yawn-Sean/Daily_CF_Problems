# https://codeforces.com/contest/526/submission/258177890
N = 10**5
C, hr, hb, wr, wb = map(int, input().split())

ret = 0
for i in range(N):
    if wr * i > C:
        break
    ret = max(ret, i * hr + (C - wr * i) // wb * hb)
for i in range(N):
    if wb * i > C:
        break
    ret = max(ret, i * hb + (C - wb * i) // wr * hr)
print(ret)
