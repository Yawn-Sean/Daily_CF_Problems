def main():
    n,k = map(int,input().split())
    ans = list(range(1,n+1))
    if k % 2 == 0:
        print(-1)
        return
    k //= 2
    def f(l,r):
        nonlocal k
        if k == 0 or l+ 1 == r: return
        m = (l + r) // 2
        ans[m-1],ans[m] = ans[m],ans[m-1]
        k -= 1
        f(l,m)
        f(m,r)
    f(0,n)
    print(*ans if k == 0 else [-1])
     
main()