# Submission link: https://codeforces.com/gym/102556/submission/368020846
def main(): 
    m = II()
    
    if m == 1:
        exit(print(1))
    
    cnt = Counter()
    
    for x in range(2, 4 * 10 ** 7):
        while m % x == 0:
            cnt[x] += 1
            m //= x
    
    if m > 1:
        cnt[m] += 1
    
    g = 0
    for x in cnt.values():
        g = math.gcd(g, 2 * x)
    
    for i in range(1, g + 1):
        if g % i == 0:
            
            factor_cnt = 1
            for x in cnt:
                factor_cnt *= 1 + 2 * cnt[x] // g * i
            
            if i * factor_cnt == g:
                ans = 1
                for x in cnt:
                    ans *= pow(x, 2 * cnt[x] // g * i)
                print(ans)
                exit()
    
    print(-1)