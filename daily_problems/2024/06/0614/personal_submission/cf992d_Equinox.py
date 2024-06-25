import sys

sys.stdin = open('in.txt', 'r')

N, k = map(int, input().split())

a = list(map(int, input().split()))
suf = [0] * N

suf[N - 1] = a[-1] == 1
for i in range(N - 2, -1, -1):
    suf[i] = (a[i] == 1) * (suf[i + 1] + 1)

res = 0

tot = sum(a) * k

for i in range(N):
    p = 1
    s = 0
    while i < N:
        if suf[i]:
            if p % k == 0 and 0 < p // k - s <= suf[i]:
                res += 1
            s += suf[i]
            i += suf[i]
        else:
            if p > tot // a[i]:
                break
            p *= a[i]
            s += a[i]
            if p % k == 0 and p // k == s:
                res += 1
            i += 1

print(res)