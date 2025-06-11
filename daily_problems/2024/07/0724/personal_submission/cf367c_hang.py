def main():
    def f(x):
        return x * (x + 1) // 2 + 1 if x % 2 == 0 else x * (x + 1) // 2 + x // 2 + 1
    n, m = map(int, input().split())
    a = []
    for _ in range(m):
        c, x = map(int, input().split())
        a.append(x)
    a.sort(reverse=True)
    ans = 0
    for i in range(m):
        if f(i) > n: break
        ans += a[i]
    print(ans)
main()