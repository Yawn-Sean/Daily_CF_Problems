from itertools import accumulate
w, l = map(int, input().split())
a = list(map(int, input().split()))
s = list(accumulate(a, initial=0))
res = min(s[i] - s[i - l] for i in range(l, len(a) + 1))
print(res)
