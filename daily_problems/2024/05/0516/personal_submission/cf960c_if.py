import sys
input = sys.stdin.readline
from bisect import bisect
x, d = map(int, input().split())
q = [2**i-1 for i in range(30)]
t = 1
w = []
while x:
    a = bisect(q, x)
    x -= q[a-1]
    w.extend([t]*(a-1))
    t += d+1
print(len(w))
print(' '.join(map(str, w)))
