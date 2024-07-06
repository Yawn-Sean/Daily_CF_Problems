from itertools import accumulate
def main():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort()
    s = list(accumulate(a,initial=0))
    ans,val = 0,0
    for i in range(n):
        l,r = 0, i
        while l<r:
            m = (l+r)//2
            t = s[i + 1] - s[m]
            p = (i - m + 1) * a[i] - t
            if p <= k:
                r = m
            else:
                l = m + 1
        if i-l+1 > ans:
            ans = i-l+1
            val = a[i]
    print(ans,val)


main()