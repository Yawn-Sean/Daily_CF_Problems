# 证明：https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/10/1002/solution/cf990d.md
def main():
    n,a,b = map(int,input().split())
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
    for x in grid:
        print(''.join(map(str, x)))

main()