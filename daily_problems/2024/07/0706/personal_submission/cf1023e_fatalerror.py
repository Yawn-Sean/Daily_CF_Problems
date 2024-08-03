import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())

def ask(r1, c1, r2, c2):
    print('?', r1, c1, r2, c2, flush=True)
    res = input()
    return res[0] == 'Y'

n = ii()
ans1 = []
r, c = 1, 1
for _ in range(n-1):
    if r < n and ask(r+1, c, n, n):
        ans1.append('D')
        r += 1
    else:
        ans1.append('R')
        c += 1

ans2 = []
r, c = n, n
for _ in range(n-1):
    if c > 1 and ask(1, 1, r, c-1):
        ans2.append('R')
        c -= 1
    else:
        ans2.append('D')
        r -= 1

print('! ', *ans1, *reversed(ans2), sep='', flush=True)