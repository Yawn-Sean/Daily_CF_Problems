def main():
    n,m = map(int,input().split())
    ans = n
    for _ in range(m):
        l,r = map(int,input().split())
        ans = min(ans,r-l+1)

    print(ans)
    r = [0] * n
    for i in range(n):
        r[i] = i % ans
    print(*r)
main()