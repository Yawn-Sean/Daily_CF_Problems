# Submission link: https://codeforces.com/gym/106806/submission/397534710
def main():
    n = II()
    p = I()
    
    v1, v2 = p.split('e')
    v1 = float(v1)
    v2 = -int(v2)
    
    for _ in range(n):
        v1 *= 1.5 - 2 * (v1 * pow(0.1, v2)) ** 2
        while abs(v1) >= 10:
            v1 /= 10
            v2 -= 1
    
    print(f'{0.5 + v1 * pow(0.1, v2):.20f}')