import sys

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/518/D

n个人排成一列，每一秒第一个人有p的概率上电梯，1-p的概率不动，求t秒后电梯人数的期望

分析：
定义dfs(i, j)表示i秒，有j个人已经上了电梯的概率，那么答案为sum(dfs(t,i)*i for i in range(1, n + 1))
dfs(0,0) = 1
dfs(i, j) = dfs(i - 1, j) * (1 - p) + dfs(i - 1, j - 1) * p

'''
n, p, t = RS().split()
p = float(p)
n, t = map(int, [n, t])

f = [[0]*(n + 1) for _ in range(t + 1)]
f[0][0] = 1
for i in range(1, t + 1):
    for j in range(mn(n, i) + 1):
        if j == n:
            # 前面已经上完了，这一秒就啥也不用干了，不能再乘(1 - p)
            f[i][j] = f[i - 1][j] + (f[i - 1][j - 1] * p if j else 0)
        else:
            f[i][j] = f[i - 1][j] * (1 - p) + (f[i - 1][j - 1] * p if j else 0)

print(sum(f[t][i] * i for i in range(1, n + 1)))