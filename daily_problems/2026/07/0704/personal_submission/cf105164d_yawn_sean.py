# Submission link: https://codeforces.com/gym/105164/submission/381103621
def main():
    n = II()
    mod = 10 ** 9 + 7
    
    total = n * (n - 1) * (n - 2) // 6
    
    for z in range(1, n - 1):
        xy_bound = fmin(z, n - z)
        total -= 3 * (xy_bound - 1) * xy_bound // 2
    
    c1 = n // 3
    c2 = 0
    
    for z in range(1, n - 1):
        l = z // 2 + 1
        r = (n - z) // 2
        c2 += fmax(r - l + 1, 0) - (l <= z <= r)
    
    total -= c1 + 3 * c2
    print((total // 6 + c1 + c2) % mod)