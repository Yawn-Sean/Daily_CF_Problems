import sys
input = lambda: sys.stdin.readline().rstrip()

def soviet():
    n = int(input())
    ans = [[1] * n for _ in range(n)]

    for i in range(n):
        for j in range(i):
            ans[i][j] = 3

    for i in range(n % 2, n):
        ans[n - 1][i] += 1

    for i in range(n):
        for j in range(n):
            print(ans[i][j], end = '')
        print()

MT = int(input())
for _ in range(MT):
    soviet()
