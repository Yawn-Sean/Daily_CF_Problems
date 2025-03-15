[n, k] = list(map(int, input().split(' ')))
a = list(map(int, input().split(' ')))
b = list(map(int, input().split(' ')))
ans = 1
for i in range(n // k):
    step = (10 ** k - 1) // a[i] - ((b[i] + 1) * (10 ** (k - 1)) - 1) // a[i] + (b[i] * (10 ** (k - 1)) - 1) // a[i] + 1
    ans = ans * step % (10 ** 9 + 7)
print(ans)