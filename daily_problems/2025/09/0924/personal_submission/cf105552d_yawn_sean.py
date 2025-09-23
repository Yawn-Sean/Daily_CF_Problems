# Submission link: https://codeforces.com/gym/105552/submission/340015891
def main():
    n, r = MII()
    
    mi_d = r
    
    for _ in range(n):
        a, b, c = MII()
        d = abs(c) / math.sqrt(a * a + b * b)
        mi_d = fmin(d, mi_d)
    
    theta = math.acos(mi_d / r)
    
    v1 = theta - math.sin(theta) * math.cos(theta)
    v1 /= math.pi
    print(v1, 1 - v1)