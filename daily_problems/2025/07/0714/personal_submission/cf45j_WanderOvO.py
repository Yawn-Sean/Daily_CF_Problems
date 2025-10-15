"""
看到了网格，想起了国际象棋
"""

n, m = map(int, input().split())
no_solution = {(1, 2), (1, 3), (2, 1), (3, 1), (2, 2)}
if (n, m) in no_solution:
    print("-1")
else:
    res = [[0 for _ in range(m)] for _ in range(n)]
    idx = 1
    for i in range(n):
        for j in range(m):
            if (i + j) % 2 != 0:
                res[i][j] = idx
                idx += 1
    for i in range(n):
        for j in range(m):
            if (i + j) % 2 == 0:
                res[i][j] = idx
                idx += 1
    for i in range(n):
        for j in range(m):
            print(res[i][j], end=" ")
        print()
