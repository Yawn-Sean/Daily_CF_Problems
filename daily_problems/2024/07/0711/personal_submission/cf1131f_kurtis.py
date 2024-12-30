import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 根据相邻格子的位置来逆推原来的排列，不一定相邻
# 启发式合并，O(nlogn)
def find(x):
    while x != p[x]:
        p[x] = p[p[x]]
        x = p[x]
    return p[x]

def union(a, b):
    a, b = find(a), find(b)
    if len(g[a]) < len(g[b]):
        g[b].extend(g[a])
        p[a] = b
    else:
        g[a].extend(g[b])
        p[b] = a

n = II()
p = [i for i in range(n)] # 并查集
g = [[i] for i in range(n)] # 每一组中的初始元素

for _ in range(n - 1):
    a, b = GMI()
    union(a, b) # 就是模拟题

for i in range(n):
    if len(g[i]) == n:
        print(*[x + 1 for x in g[i]])
        break