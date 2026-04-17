def get_min(a):
    n = len(a) - 1
    for i in range(1, n + 1):
        a.append(a[i])
    i = 1
    j = 2
    while i <= n and j <= n:
        k = 0
        while k < n and a[i + k] == a[j + k]:
            k += 1
        if k == n:
            break
        if a[i + k] > a[j + k]:
            i += k + 1
            if i == j:
                i += 1
        else:
            j += k + 1
            if i == j:
                j += 1
    return min(i, j)

n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
a_id = get_min(a)

ans = 0
for i in range(n):
    b = [0] + list(map(int, input().split()))
    b_id = get_min(b)
    j1 = a_id
    j2 = b_id
    while a[j1] == b[j2]:
        j1 = j1 % m + 1
        j2 = j2 % m + 1
        if j1 == a_id:
            exit(print(i + 1))

print(-1)
