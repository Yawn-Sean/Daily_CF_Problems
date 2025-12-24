'''
https://codeforces.com/gym/106270/submission/354922268
'''

MAXN = 10 ** 6
cost = [[0, 0] for _ in range(MAXN + 1)]
def initCosts():
    global MAXN, cost
    cost[2][0] = 2
    for y in range(4, MAXN + 1, 2):
        cost[y][0] = 2 + cost[y >> 1][0]
    for x in range(3, MAXN + 1, 2):
        if cost[x][1] == 0:
            cost[x][1] = x
            for y in range(x + x, MAXN + 1, x):
                cost[y][1] = x + cost[y // x][1]

def solve(n: int, b: int, a: int, arr: list[int]) -> int:
    global cost
    ans = sum(cost[x][0] for x in arr)
    ra, rb = n, 0
    for d in sorted(cost[x][1] - cost[x][0] for x in arr):
        if rb < b or ra > a and d < 0:
            ans += d
            ra, rb = ra - 1, rb + 1
        else:
            break
    return ans
