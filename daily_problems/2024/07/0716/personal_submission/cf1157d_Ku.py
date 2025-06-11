n,k = RII()
j = k
if k * 1 + k * (k - 1) // 2 > n:
    print('NO')
else:
    ans = []
    t = 0
    while k:
        x_max = (n - k * (k - 1) // 2) // k
        x_min = n // (2 ** k - 1) + 1 if n % (2 ** k - 1) != 0 else n // (2 ** k - 1)
        if k < j:
            x_min = max(x_min,t+1)
            x_max = min(x_max,2*t)
        t = x_max
        if x_min > x_max:
            print('NO')
            break
        ans.append(x_max)
        k -= 1
        n -= x_max
    #print(ans)
    if len(ans) == j:
        print('YES')
        print(' '.join(map(str,ans)))
