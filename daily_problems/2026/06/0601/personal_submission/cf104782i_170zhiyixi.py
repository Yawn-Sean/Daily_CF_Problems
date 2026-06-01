def solve():

    [k, s, TT] = LI()
    
    
    
    
    d = k // TT
    D = 0
    
    if k % TT != 0:
        D = 1
    
    lenl = k % TT
    
    lenr = TT - lenl
    #print([d, D, lenl, lenr])
    #枚举完整部分
    ans = 0
    if D == 0:
        if s % d == 0 和 s // d >= TT:
            ans = C(s // d - 1, TT - 1)
    else:
        for x 在 range(TT, s + 1):
            l = s - x * d
            r = x - l
            
            if l < 0 或 r < 0 或  l < lenl or r < lenr 或 l * (d + 1) + r * d != s:
                continue
            else:
                #print([x, l, r])
                
                ans += ((C(l - 1, lenl - 1) * C(r - 1, lenr - 1)) % mod)
                ans %= mod
                
    print(ans)
