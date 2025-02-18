'''
https://codeforces.com/contest/735/submission/280936286
735C
2024/9/13 Y1
1600
fib
'''

if __name__ == '__main__':
    n = int(input())
    lv, d1, d2 = 0, 1, 2

    while d2 <= n:
        d1, d2 = d2, d1 + d2
        lv += 1
    
    print(lv)