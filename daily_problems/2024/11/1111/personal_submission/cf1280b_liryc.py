'''
https://codeforces.com/problemset/submission/1280/291088533
1280B
2024/11/11 Y1
1800
'''
#ref
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m = map(int, input().split())
    grid = [input() for _ in range(n)]
    return n, m, grid

def solve(n: int, m: int, grid):
    a1 = [0] * n
    a2 = [0] * m
    
    f0 = True
    f5 = True
    
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'A':
                a1[i] += 1
                a2[j] += 1
                f5 = False
            else:
                f0 = False
    
    if f0: 
        return '0'
    elif f5: 
        return 'MORTAL'
    elif a1[0] == m or a1[n - 1] == m or a2[0] == n or a2[m - 1] == n:
        return '1'
    elif grid[0][0] == 'A' or grid[0][m - 1] == 'A' or grid[n - 1][0] == 'A' or grid[n - 1][m - 1] == 'A' or max(a1) == m or max(a2) == n:
        return '2'
    elif a1[0] or a1[n - 1] or a2[0] or a2[m - 1]:
        return '3'
    else:
        return '4'

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
