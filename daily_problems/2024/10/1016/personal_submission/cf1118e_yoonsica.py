# https://codeforces.com/contest/1118/submission/286196580
n, k = RII()
if (k - 1) * k < n:
    print('NO')
else:
    print('YES')
    a, b = 1, 2
    while n > 0:
        print(a, b)
        n -= 1
        if n:
            print(b, a)
        else:
            break
        b += 1
        if b == k + 1:
            a += 1
            b = a + 1
        n -= 1
        
    