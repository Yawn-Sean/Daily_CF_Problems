def solve():
    n = I()
    a = [0] + LI()
    ans = 0
    #横竖算重合
    f = [0] * (n + 5)
    for i in range(1, n  + 1):
        f[1] += 1
        f[min(n, a[i]) + 1] -= 1


    for i in range(1, n + 1):
        f[i] += f[i - 1]

    for i in range(1, n + 1):
        ans += a[i] - min(f[i], a[i])

    print(ans)
    
