import sys
sys.setrecursionlimit(2010) # 不能开太大，看一下最多递归多少层

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

def dfs(u):
    res = []
    for v in g[u]:
        res.extend(dfs(v))
    
    if len(res) < c[u]: # 没有这么多节点
        print("NO")
        exit()
    
    res.insert(c[u], u) # 维护一个所有的集合，这样就可以控制顺序了
    return res

# 直接递归也行，按照大小顺序把节点排好
n = II()
g = [[] for _ in range(n + 1)]
c, a = [0] * (n + 1), [0] * (n + 1)

for i in range(1, n + 1):
    fa, c[i] = MII()
    g[fa].append(i)

res = dfs(g[0][0]) # 从根节点递归下去
for i in range(n):
    a[res[i]] = i + 1

print("YES")
print(*a[1:])