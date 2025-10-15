'''
https://codeforces.com/problemset/submission/980/297662617
980 B
2024/12/21 Y1
1600
constructive
'''
# ref
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, k = map(int, input().split())
    return n, k

def solve(n: int, k: int):
    ans = [['.'] * n for _ in range(4)]
    if k & 1 == 0:
        for i in range(k >> 1):
            ans[1][i + 1] = '#'
            ans[2][i + 1] = '#'
    else:
        v = k >> 1
        ans[1][n >> 1] = '#'
        
        for i in range(1, 3):
            for j in range(1, n >> 1):
                if v:
                    v -= 1
                    ans[i][j] = '#'
                    ans[i][n - j - 1] = '#'
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print('YES')
    print(*(''.join(r) for r in ans), sep='\n')