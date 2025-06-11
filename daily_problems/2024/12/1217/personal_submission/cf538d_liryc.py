'''
https://codeforces.com/problemset/submission/538/296912530
538D
2024/12/17 Y1
1800
constructive
'''
# ref 
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    g = [input() for _ in range(n)]
    return n, g

def solve(n: int, g: list[str]):
    ans = [['x'] * (2 * n - 1) for _ in range(2 * n - 1)]

    for i in range(n):
        for j in range(n):
            if g[i][j] == 'o':
                for ni in range(n):
                    for nj in range(n):
                        if g[ni][nj] == '.':
                            ans[ni - i + n - 1][nj - j + n - 1] = '.'
    ans[n - 1][n - 1] = 'o'

    for i in range(n):
        for j in range(n):
            if g[i][j] == 'x':
                ok = False
                for di in range(2 * n - 1):
                    for dj in range(2 * n - 1):
                        if ans[di][dj] == 'x':
                            oi = i - (di - n + 1)
                            oj = j - (dj - n + 1)
                            if 0 <= oi < n and 0 <= oj < n and g[oi][oj] == 'o':
                                ok = True
                if not ok:
                    return []
    return ans

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    if ans:
        print("YES")
        print(*(''.join(x) for x in ans), sep='\n')
    else:
        print("NO")
