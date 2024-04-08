from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
a = a[1:]
s = list(accumulate(a, initial=0))

res = [0] * n
for i in range(1, n):
  k = 1
  l = i
  j = 0
  while j < n:
    res[i] += (s[min(n - 1, j + l)] - s[j]) * k
    j += l
    k += 1
    l *= i

_ = int(input())
qs = list(map(int, input().split()))
print(*[res[min(q, n - 1)] for q in qs])
