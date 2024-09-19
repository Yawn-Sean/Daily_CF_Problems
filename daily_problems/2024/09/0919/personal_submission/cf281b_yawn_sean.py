# Submission link: https://codeforces.com/contest/281/submission/281799783
def main():
    x, y, n = MII()
    
    de, nu = 1, 0
    diff_de, diff_nu = x, y
    
    for b in range(1, n + 1):
        v = b * x // y
        for a in range(v, v + 2):
            ndiff_de, ndiff_nu = abs(x * b - y * a), b * y
            if ndiff_de * diff_nu < diff_de * ndiff_nu:
                de, nu = b, a
                diff_de, diff_nu = ndiff_de, ndiff_nu
    
    print(f'{nu}/{de}')