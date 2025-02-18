def main():
    n,p = map(int,input().split())
    g = []
    ps = []
    for i in range(n):
        l,r = map(int,input().split())
        ps.append((r // p - (l - 1) // p) / (r - l + 1))
    ans = 0
    for i in range(n):
        ans += ps[i] + ps[i - 1] - ps[i] * ps[i - 1]

    print(ans * 2000)


main()
