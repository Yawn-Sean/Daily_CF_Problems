'''
https://codeforces.com/contest/990/submission/284058187
990D
2024/10/2 Y1
1700
'''

def solve():
    n, a, b = map(int, input().split())
    grid = [[0] * n for _ in range(n)]

    if a > 1:
        if b > 1:
            print('NO')
            return
        else:
            for i in range(n - a + 1):
                for j in range(n - a + 1):
                    if i != j:
                        grid[i][j] = 1
    else:
        if b > 1:
            for i in range(n):
                for j in range(n):
                    if i != j:
                        grid[i][j] = 1
            
            for i in range(n - b + 1):
                for j in range(n - b + 1):
                    if i != j:
                        grid[i][j] = 0
        else:
            if n == 2 or n == 3: 
                print('NO')
                return
            for i in range(n):
                for j in range(n):
                    if abs(i - j) == 1:
                        grid[i][j] = 1
    print('YES')
    print('\n'.join(''.join(map(str, x)) for x in grid))

if __name__ == '__main__':
    solve()
