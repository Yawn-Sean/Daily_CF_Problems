t = int(input()) 
while(t):
    n, p, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    s = 0 
    ans = 0
    for i in range(min(n, k + 1)):
        s1 = s 
        if(s > p):
            break
        c = i 
        for j in range(i + k - 1, n, k):
            if(s1 + a[j] <= p):
                s1 += a[j]
                c += k 
            else:
                break 
        s += a[i] 
        ans = max(ans, c)
    print(ans)
    t -= 1
