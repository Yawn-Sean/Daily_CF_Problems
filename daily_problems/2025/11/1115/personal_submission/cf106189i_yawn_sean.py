# Submission link: https://codeforces.com/gym/106189/submission/348885334
def main(): 
    n, xl, yl, w, h = MII()
    xr, yr = xl + w, yl + h
    xl, yl = xl - 1, yl - 1
    
    g = 0
    
    for i in range(1, 10 ** 6 + 1):
        v = n - i * i
        if v < 0: break
        w = math.isqrt(v)
        if i > w: break
        if w * w == v:
            g = math.gcd(g, i)
            g = math.gcd(g, w)
    
    ans = 0
    if g:
        ans += (xr // (2 * g) - xl // (2 * g)) * (yr // (2 * g) - yl // (2 * g))
        ans += ((xr - g) // (2 * g) - (xl - g) // (2 * g)) * ((yr - g) // (2 * g) - (yl - g) // (2 * g))
    elif xl < 0 <= xr and yl < 0 <= yr:
        ans += 1
    
    print(ans)