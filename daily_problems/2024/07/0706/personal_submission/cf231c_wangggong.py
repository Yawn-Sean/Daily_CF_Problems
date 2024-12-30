n, k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A.sort()
ans, _max = A[0], 0
S = [0] * (n + 1)
for i in range(n):
    S[i + 1] = S[i] + A[i]
for i in range(n):
    p, q = 0, i
    while p < q:
        mid = (p + q) >> 1
        if A[i] * (i - mid + 1) <= (S[i + 1] - S[mid]) + k:
            q = mid
        else:
            p = mid + 1
    if i - p + 1 > _max:
        ans, _max = A[i], i - p + 1
print(_max, ans)
