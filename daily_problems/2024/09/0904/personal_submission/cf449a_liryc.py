'''
https://codeforces.com/contest/449/submission/279824260
449 A
2024/9/4 Y1
1700
constructive: 尽量只切一侧（这样切出来的块数最少），切不下了再切另一侧
'''

def init():
    n, m, k = map(int, input().split())
    return n, m, k

def solve(n: int, m: int, k):
    if k > n - 1 + m - 1:
        return -1
    elif k > n - 1:
        l = k - (n - 1)
        return m // (l + 1)
    else:
        return n // (k + 1) * m

if __name__ == '__main__':
    n, m, k = init()
    ans = max(solve(n, m, k), solve(m, n, k)) if n != m else solve(n, m, k)
    print(ans)
