import bisect


k = int(input())
a = [0] * 12
for i in range(1, 12):
    a[i] += i * 9 * 10 ** (i - 1) + a[i - 1]
n = bisect.bisect_left(a, k) - 1
k -= a[n] + 1
m = 10 ** n + k // (n + 1)
print(str(m)[k % (n + 1)])
