def main():
    n,m,a = map(int,input().split())
    b = list(map(int,input().split()))
    p = list(map(int,input().split()))
    #r,s = 0, 0
    p.sort()
    b.sort()
    l,r = 0, min(n,m)
    while l < r:
        mid = (l + r + 1) // 2
        tot = 0
        for i in range(mid):
            tot += max(0, p[i] - b[n - mid + i])
            if tot > a:
                r = mid - 1
                break
        else:
            l = mid
    print(l, max(0, sum(p[:r]) - a))
            
main()