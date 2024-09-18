def CF340E():
    c = Comb()
    n = II()
    a = LII()
    
    s1 = set(range(1, n + 1))
    s2 = set()
    for i, x in enumerate(a, 1):
        if x == -1: s2.add(i)
        else: s1.remove(x)    
        
    x0 = len(s1 & s2)   # 可能产生固定点的位置
    x1 = len(s1) - x0   # 不可能产生固定点的位置
    ans = 0
    op = 1
    for i in range(x0 + 1):
        ans += op * c.fact[x0 + x1 - i] * c.comb(x0, i)
        op *= -1
        ans %= MOD1
    print(ans)
