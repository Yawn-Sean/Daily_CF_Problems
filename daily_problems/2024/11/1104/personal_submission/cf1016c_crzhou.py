N = 300010
n = int(input())
a = [0] * N
b = [0] * N
A1 = [0] * N
B1 = [0] * N
A2 = [0] * N
B2 = [0] * N
A = [0] * N
B = [0] * N
l, r, ans = 0, 0, 0

a[1:n+1] = list(map(int, input().split()))
b[1:n+1] = list(map(int, input().split()))

for i in range(1, n + 1):
    A1[i] = A1[i - 1] + (i - 1) * a[i]
    B1[i] = B1[i - 1] + (i - 1) * b[i]

for i in range(n, 0, -1):
    A2[i] = A2[i + 1] + (n - i) * a[i]
    B2[i] = B2[i + 1] + (n - i) * b[i]

for i in range(1, n + 1):
    A[i] = A[i - 1] + a[i]
    B[i] = B[i - 1] + b[i]

ans = A1[n] + B2[1] + B[n] * n

for i in range(1, n + 1):
    if i % 2 == 1:
        l += a[i] * (i * 2 - 2) + b[i] * (i * 2 - 1)
    else:
        l += a[i] * (i * 2 - 1) + b[i] * (i * 2 - 2)

    if i % 2 == 1:
        r = B1[n] - B1[i] + (B[n] - B[i]) * i + A2[i + 1] + (A[n] - A[i]) * (n + i)
    else:
        r = A1[n] - A1[i] + (A[n] - A[i]) * i + B2[i + 1] + (B[n] - B[i]) * (n + i)

    ans = max(ans, l + r)

print(ans)
