import sys

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 把一颗树按3个节点依次拆开
# 如果总个数不是3的倍数，直接-1
# 写一个dfs函数，求剩余子树还未分配的节点数目
# 然后加到父节点上，如果父节点的负重值大于3，返回-1；等于3，记录上一条边；小于3返回给父父节点处理

def dfs(u, fa, idx):
    cnt = 0
    for v, nxt in g[u]:
        if v == fa: continue
        cnt += dfs(v, u, nxt)
    if cnt < 2:
        return cnt + 1
    elif cnt == 2: # 贪心的分割
        if idx != -1:
            ans.append(idx)
        return 0
    else:
        global flag
        flag = True
        return 0

outs = []
for _ in range(II()):
    n = II()
    g = [[] for _ in range(n)]
    for i in range(n - 1):
        a, b = GMI()
        g[a].append((b, i + 1))
        g[b].append((a, i + 1))

    if n % 3:
        outs.append(-1)
        continue # 得输入完才能退出
    ans = []
    flag = False
    dfs(0, -1, -1)
    if flag: outs.append(-1)
    else: outs.append(ans)

for out in outs:
    if out == -1:
        print(-1)
    else:
        print(len(out))
        print(*out)