'''
https://codeforces.com/problemset/submission/1580/291387771
1580 A
2024/11/14 Y1
1700
'''
# ref
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m = map(int, input().split())
    grid = [[int(x) for x in input()] for _ in range(n)]
    return n, m, grid

def solve(n: int, m: int, grid: list[list[int]]):
        ans = n * m
        cnt = [0] * m
        calc = [0] * m

        for i in range(n - 4):
            for j in range(m):
                cnt[j] = 0
            
            for j in range(i + 1, i + 4):
                for k in range(m):
                    cnt[k] += grid[j][k]
            
            for j in range(i + 4, n):
                for k in range(m):
                    calc[k] = cnt[k]
                    
                for k in range(1, m - 1):
                    calc[k] += 2 - grid[i][k] - grid[j][k]
                
                for k in range(1, m):
                    calc[k] += calc[k - 1]
                
                cur = n * m
                for k in range(m - 1, 2, -1):
                    cur = min(cur, calc[k - 1] + j - i - 1 - cnt[k])
                    ans = min(ans, cur - calc[k - 3] + j - i - 1 - cnt[k - 3])
                
                for k in range(m):
                    cnt[k] += grid[j][k]
        return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
