import sys
input = lambda: sys.stdin.readline().rstrip()
lii = lambda: list(map(int, input().split()))

from itertools import accumulate

n, k = lii()
arr = lii()
pres = list(accumulate(arr, initial=0))
ans = min(pres[i]-pres[i-k] for i in range(k, n))
print(ans)
