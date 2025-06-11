def main():
    n,k,x = map(int,input().split())
    a = list(map(int,input().split()))
    x = pow(x, k)
    pre = a[:]
    suf = a[:]
    for i in range(1,n):
        pre[i] = pre[i] | pre[i-1]
    for i in range(n-2,-1,-1):
        suf[i] = suf[i] | suf[i+1]
    if n == 1:
        print(pre[0] * x)
        return
    ans = max((a[0] * x) | suf[1], (a[n-1] * x) | pre[n-2])
    for i in range(1,n-1):
        ans = max(ans, (a[i] * x) | pre[i-1] | suf[i + 1])
    print(ans)
        

main()