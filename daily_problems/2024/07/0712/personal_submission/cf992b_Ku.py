l,r,x,y = RII()
ans = 0
if y % x : print(0)
elif y == x:
    ans = 1 if  l <= x <= r else 0
    print(ans)
else:
    opt = y // x

    for i in range(1,isqrt(opt) + 1):
        if opt % i == 0:
            if gcd(opt // i,i) == 1 and l <= i * x <= r and l <= opt // i * x <= r:
                ans += 2
    print(ans)
