def main():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    r = sorted(range(n), key=lambda i: a[i])
    ans = [0] * n
    for i in range(0,n,2):
        ans[r[i]] = 1

    print(*ans)

main()