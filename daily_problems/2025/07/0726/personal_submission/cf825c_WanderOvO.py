n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

res = 0
for i in range(n):
    while a[i] > 2 * k:
        k *= 2
        res += 1
print(res)
