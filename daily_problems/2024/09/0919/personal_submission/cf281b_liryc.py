'''
https://codeforces.com/contest/281/submission/281804959
281B
2024/9/19 Y1
math
'''

# ref
if __name__ == '__main__':
    x, y, n = map(int, input().split())
    
    de, nu = 1, 0
    diff_de, diff_nu = x, y
    
    for b in range(1, n + 1):
        a = b * x // y
        for i in range(2):
            a += i
            ndiff_de, ndiff_nu = abs(x * b - y * a), b * y
            if ndiff_de * diff_nu < diff_de * ndiff_nu:
                de, nu = b, a
                diff_de, diff_nu = ndiff_de, ndiff_nu
    
    print(f'{nu}/{de}')