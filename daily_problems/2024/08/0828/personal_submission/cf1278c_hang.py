def main():
    n = int(input())
    a = list(map(int, input().split()))
    p = [-n] * ( 2 * n + 1)
    cur = 0
    p[0] = 0
    for i in range(n):
        cur += 1 if a[i] == 1 else -1
        p[cur] = i + 1
    cur = 0
    mx = p[0] # mx指的是可以剩下的罐子的最大的数量
    for i in range(2 * n - 1, n - 1, -1):
        cur += 1 if a[i] == 1 else -1
        mx = max(mx, p[-cur] + n * 2 - i)
    print(2 * n  - mx)

t = int(input())
for _ in range(t):
    main()